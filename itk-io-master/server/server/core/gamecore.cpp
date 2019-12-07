#include "gamecore.h"
#include <map>
#include "ship.h"
#include "environment.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <mutex>

using namespace std;

GameCore::GameCore( int sizeX, int sizeY, float drag, float stepSize,  int msPerStep):environment(sizeX,sizeY,drag,stepSize,msPerStep)
{
    qDebug() << "GameCore created.";
    nextShipID = 0;
    stepInProgress = false;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulationStep()));
    qDebug() << environment.msPerStep;
    timer->start(environment.msPerStep);
}

void GameCore::simulationStep(){
    if(!stepInProgress){
        stepInProgress = true;

        //Szerverhez kapcsolódás, onnan lelépés
        joinQueueMutex.lock();
        for(pair<int,string> joinPair : joinQueue){
            ships[joinPair.first]=Ship(joinPair.first,joinPair.second);
            qDebug() << "Player ID "<<joinPair.first<<" joined server.";
        }
        joinQueue.clear();
        joinQueueMutex.unlock();
        exitQueueMutex.lock();
        for(int exitId : exitQueue){
            ships.erase(exitId);
            inGameIDs.erase(exitId);
        }
        exitQueue.clear();
        exitQueueMutex.unlock();

        //játékhoz kapcsolódás, onnan kilépés
        for(pair<int, Ship> s : ships){
            if(ships[s.second.id].checkIfWannaJoin(*this))inGameIDs.insert(s.first);
            if(!ships[s.second.id].checkIfStillInGame())inGameIDs.erase(s.first);
        }

        //lövés
        for(int i:inGameIDs){
            ships[i].mayShoot(ships, inGameIDs);
        }

        //hajók haladása
        for(int i:inGameIDs){
            ships[i].move(environment.stepSize,environment.drag);
        }

        //Ütközések            TODO ütközések
        //I. hajó ütközik hajóval
        for(int i:inGameIDs){
            for(int j:inGameIDs){
                if(i<j){ //hogy minden párt csak egyszer nézzen meg
                    if(ships[i].getShape()->collidesWithItem(ships[j].getShape())){ //ütköznek?
                        qDebug()<<"CRASH!";
                        if(ships[i]<=ships[j])ships[i]._startsSink();
                        if(ships[j]<=ships[i])ships[j]._startsSink();
                    }
                }
            }
        }
        //II. hajó a pálya szélével
        for(int i:inGameIDs){
            ShipGraphicItem* shipShape = ships[i].getShape();
            if(shipShape->collidesWithItem(environment.upperWall) || shipShape->collidesWithItem(environment.lowerWall)
                    || shipShape->collidesWithItem(environment.leftWall) || shipShape->collidesWithItem(environment.rightWall)){
                ships[i]._startsSink();
                qDebug()<<"CRASH!";
            }
        }

        //szintlépés
        for(int i:inGameIDs){
            ships[i].refreshLevel();
        }
        stepInProgress=false;
    }
}

/*void GameCore::joinPlayer(string name){
    ships[nextShipID]=Ship(nextShipID,name);
    nextShipID++;
}*/

void GameCore::leftPlayer(int id){
    exitQueueMutex.lock();
    exitQueue.push_back(id);
    exitQueueMutex.unlock();
}

void GameCore::playerJoined(int id, string name){
    qDebug()<<"Player joiner gamecore with id:"<<id;
    joinQueueMutex.lock();
    joinQueue.push_back(pair<int,string>(id, name));
    joinQueueMutex.unlock();
}

void GameCore::quitFromGame(int id)
{

}

void GameCore::shoot(int id, fireDirection direction)
{
    switch (direction) {
    case fireDirection::NONE:
        ships[id].leftCannonsWill=false;
        ships[id].rightCannonsWill=false;
        break;
    case fireDirection::LEFT:
        ships[id].leftCannonsWill=true;
        ships[id].rightCannonsWill=false;
        break;
    case fireDirection::RIGHT:
        ships[id].leftCannonsWill=false;
        ships[id].rightCannonsWill=true;
        break;
    case fireDirection::LEFTRIGHT:
        ships[id].leftCannonsWill=true;
        ships[id].rightCannonsWill=true;
        break;
    }
}

Environment GameCore::getEnvironment(){
    return this->environment;
}

void GameCore::generateNewShipLocation(float &locX, float &locY, float &phi) const{
    //TODO
    locX=10+15*inGameIDs.size();
    locY=10;
    phi=90;
}

int GameCore::getX(int id){
    return ships[id].locX;
}

int GameCore::getY(int id){
    return ships[id].locY;
}

int GameCore::getPhi(int id){
    return ships[id].phi;
}

int GameCore::getLife(int id)
{
    return ships[id].life;
}

int GameCore::getScore(int id)
{
    return ships[id].score;
}

int GameCore::getLevel(int id)
{
    return ships[id].level;
}

int GameCore::getDamage(int id)
{
    return ships[id].damage;
}

int GameCore::getReloadTime(int id)
{
    return ships[id].reloadTime;
}


int GameCore::getRechargeTime(int id)
{
 return ships[id].reloadTime;
}

int GameCore::getMaxLife(int id)
{
    return ships[id].maxLife;
}

float GameCore::getSize(int id)
{
    return ships[id].size;
}

float GameCore::getRange(int id)
{
    return ships[id].range;
}

bool GameCore::isInGame(int id){
    return ships[id].inGame;
}



void GameCore::speed(int id, verticalDirection direction){
    qDebug()<<"speed increased";
    ships[id].speedWill=direction;
}

void GameCore::turn(int id, turnDirection direction){
    ships[id].turnWill=direction;
}

void GameCore::joinToGame(int id){
    ships[id].wannaJoin=true;
}

long GameCore::lastHitGot(int id)
{
    std::chrono::time_point<std::chrono::steady_clock> lastHitGot = ships[id].lastAcceptedHit;
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-lastHitGot);
            long myDuration = milliseconds.count();
    return myDuration;
}

long GameCore::lastFireLeft(int id)
{
    std::chrono::time_point<std::chrono::steady_clock> lastFireLeft = ships[id].lastLeftShoot;
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-lastFireLeft);
            long myDuration = milliseconds.count();
    return myDuration;
}

long GameCore::lastFireRight(int id)
{
    std::chrono::time_point<std::chrono::steady_clock> lastFireRight = ships[id].lastRightShoot;
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-lastFireRight);
            long myDuration = milliseconds.count();
    return myDuration;
}

long GameCore::lastStartedSink(int id)
{
    std::chrono::time_point<std::chrono::steady_clock> lastStartedSink = ships[id].lastSinked;
            auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-lastStartedSink);
            long myDuration = milliseconds.count();
    return myDuration;
}



fireDirection GameCore::getFireCapability(int id)
{

}


