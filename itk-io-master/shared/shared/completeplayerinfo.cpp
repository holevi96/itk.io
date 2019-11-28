#include "completeplayerinfo.h"

CompletePlayerInfo::CompletePlayerInfo()
{

}
CompletePlayerInfo::CompletePlayerInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft,
                                       long lastFireRight, long lastHitted, long lastSink, fireDirection firing,
                                       bool gettingHit, bool sinking,fireDirection fireCapability, int life,
                                       int maxLife, int rechargeTime,QString name, Design design):
score(score),x(x),y(y),phi(phi),size(size),
  lastFireLeft(lastFireLeft),lastFireRight(lastFireRight),lastHitted(lastHitted),lastSink(lastSink),
  fireCapability(fireCapability),life(life),maxLife(maxLife),rechargeTime(rechargeTime),name(name),design(design)
{
    this->id = id;
}
