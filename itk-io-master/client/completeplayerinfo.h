#ifndef COMPLETEPLAYERINFO_H
#define COMPLETEPLAYERINFO_H
#include "../shared/shared/globalconstants.h"
#include "../shared/shared/design.h"
#include <QtCore>

class CompletePlayerInfo
{
public:
    CompletePlayerInfo();
    CompletePlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking, fireDirection fireCapability, int life, int maxLife, int rechargeStatus, int rechargeTime, QString name, Design design);
private:
    int id;
    int score;
    int x;
    int y;
    int phi;
    int size;
    fireDirection firing;
    bool gettingHit;
    bool sinking;
    fireDirection fireCapability;
    int life;
    int maxLife;
    int rechargeStatus;
    int rechargeTime;
    QString name;
    Design design;
};

#endif // COMPLETEPLAYERINFO_H
