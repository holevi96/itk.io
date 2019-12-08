#include "completeplayerinfo.h"

CompletePlayerInfo::CompletePlayerInfo()
{
    this->id = -1;
}

void CompletePlayerInfo::printForDebug()
{
    qDebug()<<"printForDebug:";
    qDebug()<<"\tname: "<<name;
    qDebug()<<"\tlife: "<<life;
    qDebug()<<"\tid: "<<id;
    qDebug()<<"\tx: "<<x;
    qDebug()<<"\ty: "<<y;
    qDebug()<<"\tsize: "<<size;
    qDebug()<<"\tscore: "<<score;
    qDebug()<<"\tphi: "<<phi;
}
CompletePlayerInfo::CompletePlayerInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft,
                                       long lastFireRight, long lastHitted, long lastSink, fireDirection firing,
                                       bool gettingHit, bool sinking,fireDirection fireCapability, int life,
                                       int maxLife, int rechargeTime,QString name, Design* design):
score(score),x(x),y(y),phi(phi),size(size),
  lastFireLeft(lastFireLeft),lastFireRight(lastFireRight),lastHitted(lastHitted),lastSink(lastSink),
  fireCapability(fireCapability),life(life),maxLife(maxLife),rechargeTime(rechargeTime),name(name),design(design)
{
    this->id = id;
}

CompletePlayerInfo::CompletePlayerInfo(int id, QString name, Design* design):
    score(0),x(0),y(0),phi(0),size(0),
      lastFireLeft(0),lastFireRight(0),lastHitted(0),lastSink(0),
      fireCapability(fireDirection::NONE),life(0),maxLife(0),rechargeTime(0),name(name),design(design)
{
   this->id = id;
}


void CompletePlayerInfo::setMinimalinfo(int id, int score, long lastFireLeft, long lastFireRight, long lastHitted, long lastSink){
    this->score = score;

    this->lastFireLeft = lastFireLeft;
    this->lastFireRight = lastFireRight;
    this->lastHitted = lastHitted;
    this->lastSink = lastSink;
}



void CompletePlayerInfo::setAdvancedInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft,
                                         long lastFireRight, long lastHitted, long lastSink, int life, int maxLife){
    this->score = score;
    this->id = id;
    this->x = x;
    this->y = y;
    this->phi = phi;
    this->size = size;
    this->lastFireLeft = lastFireLeft;
    this->lastFireRight = lastFireRight;
    this->lastHitted = lastHitted;
    this->lastSink = lastSink;
    this->life = life;
    this->maxLife = maxLife;

}



void CompletePlayerInfo::setOwnInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft, long lastFireRight,
                                    long lastHitted, long lastSink,fireDirection fireCapability, int life, int maxLife,int rechargeTime)

{
    this->score = score;
    this->id = id;
    this->x = x;
    this->y = y;
    this->phi = phi;
    this->size = size;
    this->lastFireLeft = lastFireLeft;
    this->lastFireRight = lastFireRight;
    this->lastHitted = lastHitted;
    this->lastSink = lastSink;
    this->life = life;
    this->maxLife = maxLife;
    this->rechargeTime = rechargeTime;

}


Design* CompletePlayerInfo::getDesign() const
{
    return design;
}

QString CompletePlayerInfo::getName() const
{
    return name;
}

int CompletePlayerInfo::getRechargeTime() const
{
    return rechargeTime;
}



int CompletePlayerInfo::getMaxLife() const
{
    return maxLife;
}

int CompletePlayerInfo::getLife() const
{
    return life;
}

fireDirection CompletePlayerInfo::getFireCapability() const
{
    return fireCapability;
}

long CompletePlayerInfo::getLastSink() const
{
    return lastSink;
}

long CompletePlayerInfo::getLastHitted() const
{
    return lastHitted;
}

long CompletePlayerInfo::getLastFireRight() const
{
    return lastFireRight;
}

long CompletePlayerInfo::getLastFireLeft() const
{
    return lastFireLeft;
}

int CompletePlayerInfo::getSize() const
{
    return size;
}

int CompletePlayerInfo::getPhi() const
{
    return phi;
}

int CompletePlayerInfo::getY() const
{
    return y;
}

int CompletePlayerInfo::getX() const
{
    return x;
}

int CompletePlayerInfo::getScore() const
{
    return score;
}

int CompletePlayerInfo::getId() const
{
    return id;
}
