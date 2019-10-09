#include "ship.h"
#include "acceleration.h"
#include "environment.h"
#include <math.h>

Ship::Ship(int _id, string _name){
    name = _name;
    id = _id;
    score = 0;
    acceleration = Acceleration();
    wannaJoin = false;
}

Ship::Ship(){}

void Ship::init(const Environment &environment){
    acceleration.reset();
    velForward=0;
    velPhi=0;
    environment.generateNewShipLocation(locX,locY,phi);
    leftCannonsWill=false;
    rightCannonsWill=false;
    forwardWill=false;
    backwardWill=false;
    turningRightWill=false;
    turningLeftWill=false;
    inGame = true;
    justSinked = false;
    wannaJoin = false;
    leftCannonsReady=true;
    rightCannonsReady=true;
    shootingLeft=false;
    shootingRight=false;
    gettingHit=false;
    score = 0;
    level = -1;
    refreshLevel();
}

void Ship::refreshLevel(){
    int newLevel = score / 100 + 1;
    if(level!=newLevel){
        level = newLevel;
        damage = 60 * pow(1.2,level);
        maxLife = 100 * pow(1.2,level);
        life = maxLife;
        reloadTime = 2000 + level * 100;
        size = 1 + 0.1 * level;
        range = 100;
    }
}

void Ship::move(float stepSize, float drag){
    acceleration.refreshVelocities(velForward, velPhi, stepSize, drag, forwardWill, backwardWill, turningRightWill, turningLeftWill);
}

void Ship::mayShoot(map<int, Ship> &ships, set<int> &inGameIDs, GameCore &gameCore){
    if(leftCannonsWill && leftCannonsReady){
        shootingLeft=true;
        lastLeftShoot = std::chrono::steady_clock::now();
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

bool Ship::checkIfWannaJoin(const Environment &environment){
    if(wannaJoin){
        inGame=true;
        init(environment);
        return true;
    }else{
        return false;
    }
}
