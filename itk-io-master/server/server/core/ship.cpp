#include "ship.h"
#include "acceleration.h"
#include "environment.h"
#include <math.h>
#include "shipgraphicitem.h"
#include <QDebug>
#include <vector>

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
    lastAcceptedHit=std::chrono::steady_clock::now()-std::chrono::hours(1);
    lastLeftShoot=std::chrono::steady_clock::now()-std::chrono::hours(1);
    lastRightShoot=std::chrono::steady_clock::now()-std::chrono::hours(1);
    lastSinked=std::chrono::steady_clock::now()-std::chrono::hours(1);
    score = 0;
    level = -1;
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
    //float x = shape->x();
    //float y = shape->y();
    //float r = shape->rotation();
    //int i = 7*7;
}

bool compareShipsByDistance(pair<Ship*,Ship*> &a, pair<Ship*,Ship*> &b){
    float distA,distB;
    distA = (a.first->locX-a.second->locX)*(a.first->locX-a.second->locX)+(a.first->locY-a.second->locY)*(a.first->locY-a.second->locY);
    distB = (b.first->locX-b.second->locX)*(b.first->locX-b.second->locX)+(b.first->locY-b.second->locY)*(b.first->locY-b.second->locY);
    return distA<distB;
}

void Ship::mayShoot(map<int, Ship> &ships, set<int> &inGameIDs){
    auto now = std::chrono::steady_clock::now();
    bool leftShotOccures=leftCannonsWill && std::chrono::duration_cast<std::chrono::milliseconds>(now-lastLeftShoot).count()>reloadTime;
    bool rightShotOccures=rightCannonsWill && std::chrono::duration_cast<std::chrono::milliseconds>(now-lastRightShoot).count()>reloadTime;
    leftCannonsWill = false;
    rightCannonsWill = false;
    if(leftShotOccures || rightShotOccures){
        vector<pair<Ship*,Ship*>> pairTargets;
        for(int i : inGameIDs){
            if(i!=id){
                pairTargets.push_back(make_pair(this,&ships[i]));
            }
        }
        sort(pairTargets.begin(), pairTargets.end(), compareShipsByDistance);
        vector<Ship*> targets; //sorted targets
        for(pair<Ship*,Ship*> p : pairTargets){
            targets.push_back(p.second);
        }

        if(leftShotOccures){
            qDebug()<<"leftShoot"<<id;

            lastLeftShoot = now;

            QGraphicsRectItem shot(-range, -size/2, range, size);
            shot.setPos(shape->pos());
            shot.setRotation(shape->rotation());

            for(Ship* target : targets){
                if(target->getShape()->collidesWithItem(&shot)){
                    score+=target->hitted(damage);
                    break;
                }
            }
        }
        if(rightShotOccures){
            qDebug()<<"rightShoot"<<id;

            lastRightShoot = now;

            QGraphicsRectItem shot(0, -size/2, range, size);
            shot.setPos(shape->pos());
            shot.setRotation(shape->rotation());

            for(Ship* target : targets){
                if(target->getShape()->collidesWithItem(&shot)){
                    score+=target->hitted(damage);
                    break;
                }
            }
        }
    }
}

int Ship::hitted(int damage){
    lastAcceptedHit = std::chrono::steady_clock::now();
    if(life>damage)
    {
        life-=damage;
        return damage;
    } else{
        int returnValue = life;
        life=0;
        _startsSink();
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
