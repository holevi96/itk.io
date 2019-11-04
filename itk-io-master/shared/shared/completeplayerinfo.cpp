#include "completeplayerinfo.h"

CompletePlayerInfo::CompletePlayerInfo()
{

}
CompletePlayerInfo::CompletePlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking,fireDirection fireCapability, int life, int maxLife, int rechargeStatus, int rechargeTime,QString name, Design design):
score(score),x(x),y(y),phi(phi),size(size),firing(firing),gettingHit(gettingHit),sinking(sinking),fireCapability(fireCapability),life(life),maxLife(maxLife),rechargeStatus(rechargeStatus),rechargeTime(rechargeTime),name(name),design(design)
{
    this->id = id;
}
