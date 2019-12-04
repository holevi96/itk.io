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
    virtual ~OwnPlayerInfo() override;
    OwnPlayerInfo(int id, int score, int x, int y, int phi, int size,
                  long lastFireLeft, long lastFireRight, long lastHitted,
                  long lastSink, fireDirection fireCapability,
                  int life, int maxLife, int rechargeTime);
    QString getSerializedClass() override;
    void setClassBySerializedString(QString serial);
    QString getName() override;
    int getScore() const;

    int getX() const;

    int getY() const;

    int getPhi() const;

    int getSize() const;

    long getLastFireLeft() const;

    long getLastFireRight() const;

    long getLastHitted() const;

    long getLastSink() const;

    fireDirection getFireCapability() const;

    int getLife() const;

    int getMaxLife() const;

    int getRechargeTime() const;

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
