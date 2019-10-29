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

        for(pair<int, Ship> s : ships){
            if(s.second.checkIfWannaJoin(environment))inGameIDs.insert(s.first);
            if(!s.second.checkIfStillInGame())inGameIDs.erase(s.first);
        }

        /*for(int i:inGameIDs){
            ships[i].mayShoot(ships, inGameIDs);
        }*/

        for(int i:inGameIDs){
            ships[i].refreshLevel();
        }

        for(int i:inGameIDs){
            ships[i].move(environment.stepSize,environment.drag);
        }

        //TODO ütközések

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
    exitQueueMutex.lock();
}
void GameCore::playerJoined(int id, string name){
    joinQueueMutex.lock();
    joinQueue.push_back(pair<int,string>(id, name));
    joinQueueMutex.unlock();
}
Environment GameCore::getEnvironment(){
    return this->environment;
}
