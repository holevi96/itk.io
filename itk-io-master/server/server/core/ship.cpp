#include "ship.h"
#include "acceleration.h"
#include "environment.h"
#include <math.h>
#include "shipgraphicitem.h"
#include <QDebug>

Ship::Ship(int _id, string _name){
    name = _name;
    id = _id;
    score = 0;
    acceleration = Acceleration();
    wannaJoin = false;
    inGame = false;
    shape = nullptr;
}

Ship::Ship(){}

void Ship::init(const GameCore &gameCore){
    acceleration.reset();
    velForward=0;
    velPhi=0;
    gameCore.generateNewShipLocation(locX,locY,phi);
    leftCannonsWill=false;
    rightCannonsWill=false;
    speedWill=verticalDirection::REST;
    turnWill=turnDirection::REST;
    inGame = true;
    justSinked = false;
    wannaJoin = false;
    leftCannonsReady=true;
    rightCannonsReady=true;
    shootingLeft=false;///
    shootingRight=false;///
    gettingHit=false;///
    lastAcceptedHit=lastLeftShoot.min();
    lastLeftShoot=lastLeftShoot.min();
    lastRightShoot=lastLeftShoot.min();
    lastSinked=lastLeftShoot.min();
    score = 0;
    level = -1;

    //mi a helyzet a recharestatus és rechargetime-al?


    refreshLevel();
    //qDebug()<<"jatekban!!!!!!!!!!!!!!!!!!!!!!!!!"<<wannaJoin<<id;
}

void Ship::refreshLevel(){
    int newLevel = score / 100 + 1;
    if(level!=newLevel){
        level = newLevel;
        damage = 60 * pow(1.2,level);
        maxLife = 100 * pow(1.2,level);
        life = maxLife;
        reloadTime = 2000 + level * 100;
        size = 10 + 1 * level;
        range = 100;
        delete shape;
        shape = new ShipGraphicItem(size);
    }
}

void Ship::move(float stepSize, float drag){
    acceleration.refreshVelocities(velForward, velPhi, stepSize, drag, speedWill, turnWill);
    locX+=cos(phi)*velForward*stepSize;
    locY+=sin(phi)*velForward*stepSize;
    phi+=velPhi*stepSize;
    while(phi<0)phi+=360;
    while(phi>=360)phi-=360;
    //shape->setPos(0,0);
    shape->setRotation(90-phi);
    shape->setPos(locX, locY);
    float x = shape->x();
    float y = shape->y();
    float r = shape->rotation();
    int i = 7*7;
}

void Ship::mayShoot(map<int, Ship> &ships, set<int> &inGameIDs, GameCore &gameCore){
    if(leftCannonsWill && leftCannonsReady){
        shootingLeft=true;
        lastLeftShoot = std::chrono::steady_clock::now();
        //auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(lastLeftShoot - std::chrono::steady_clock::now());
        //long myDuration = milliseconds.count();
        //TODO találat detektálás
    }
    if(rightCannonsWill && rightCannonsReady){
        shootingRight=true;
        //errort dobott a következő sor:
       // shootingLeft = std::chrono::steady_clock::now();


        //TODO találat detektálás
    }
}

int Ship::hitted(int damage){
    if(life>damage)
    {
        life-=damage;
        return damage;
    } else{
        int returnValue = life;
        life=0;
        justSinked=true;
        return returnValue;
    }
}

bool Ship::checkIfStillInGame(){
    if(justSinked){
        inGame=false;
        return false;
    }else{
        return true;
    }
}

bool Ship::checkIfWannaJoin(const GameCore &gameCore){
    if(wannaJoin && !inGame){
        inGame=true;
        init(gameCore);
        return true;
    }else{
        return false;
    }
}

ShipGraphicItem *Ship::getShape(){
    return shape;
}

bool Ship::operator < (Ship const &s2){
    return this->level<s2.level;
}

bool Ship::operator > (Ship const &s2){
    return this->level>s2.level;
}

bool Ship::operator == (Ship const &s2){
    return this->level==s2.level;
}

bool Ship::operator <= (Ship const &s2){
    return this->level<=s2.level;
}

bool Ship::operator >= (Ship const &s2){
    return this->level>=s2.level;
}

void Ship::_startsSink(){
    justSinked=true;
    lastSinked=std::chrono::steady_clock::now();
    qDebug()<<id<<" is sinking.";
}
