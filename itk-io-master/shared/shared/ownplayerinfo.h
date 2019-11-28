#ifndef OWNPLAYERINFO_H
#define OWNPLAYERINFO_H
#include "serializable.h"
#include "playerinfo.h"
#include "serializehelper.h"
#include "globalconstants.h"

class OwnPlayerInfo : public Playerinfo
{
public:
    OwnPlayerInfo(QString serial);
    virtual ~OwnPlayerInfo();
    OwnPlayerInfo(int id, int score, int x, int y, int phi, int size,
                  long lastFireLeft, long lastFireRight, long lastHitted,
                  long lastSink, fireDirection firing, bool gettingHit,
                  bool sinking, fireDirection fireCapability,
                  int life, int maxLife, int rechargeTime);
    QString getSerializedClass();
    void setClassBySerializedString(QString serial);
private:
    int score;
    int x;
    int y;
    int phi;
    int size;
    /*fireDirection firing;
    bool gettingHit;
    bool sinking;*/
    long lastFireLeft;
    long lastFireRight;
    long lastHitted;
    long lastSink;
    fireDirection fireCapability;
    int life;
    int maxLife;
    int rechargeTime;
};

#endif // OWNPLAYERINFO_H
