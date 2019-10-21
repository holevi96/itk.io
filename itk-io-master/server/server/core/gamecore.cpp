#include "gamecore.h"
#include <map>
#include "ship.h"
#include "environment.h"
#include <QTimer>
#include <QObject>
#include <QDebug>

using namespace std;

GameCore::GameCore( int sizeX, int sizeY, float drag, float stepSize,  int msPerStep)
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
        //TODO kilépés, belépés

        for(pair<int, Ship> s : ships){
            if(s.second.checkIfWannaJoin(environment))inGameIDs.insert(s.first);
            if(!s.second.checkIfStillInGame())inGameIDs.erase(s.first);
        }

        /*for(int i:inGameIDs){
            ships[i].mayShoot(ships, inGameIDs);
        }*/

        //for(int i:inGameIDs){
        //    ships[i].refreshLevel();
        //}

        for(int i:inGameIDs){
            ships[i].move(environment.stepSize,environment.drag);
        }

        //TODO ütközések

        stepInProgress=false;
    }
}

void GameCore::joinPlayer(string name){
    ships[nextShipID]=Ship(nextShipID,name);
    nextShipID++;
}

void GameCore::leftPlayer(int id){
    ships.erase(id);
    inGameIDs.erase(id);
}
void GameCore::playerJoined(int id){
    qDebug() << "Player ID "<<id<<" joined server.";
}
