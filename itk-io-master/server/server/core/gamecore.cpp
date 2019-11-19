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
            if(s.second.checkIfWannaJoin(*this))inGameIDs.insert(s.first);
            if(!s.second.checkIfStillInGame())inGameIDs.erase(s.first);
        }

        //lövés
        /*for(int i:inGameIDs){
            ships[i].mayShoot(ships, inGameIDs);
        }*/

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
                        if(ships[i]<=ships[j])ships[i]._startsSink();
                        if(ships[j]<=ships[i])ships[j]._startsSink();
                    }
                }
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
    joinQueueMutex.lock();
    joinQueue.push_back(pair<int,string>(id, name));
    joinQueueMutex.unlock();
}
Environment GameCore::getEnvironment(){
    return this->environment;
}

void GameCore::generateNewShipLocation(float &locX, float &locY, float &phi) const{
    //TODO
    locX=0;
    locY=0;
    phi=0;
}
