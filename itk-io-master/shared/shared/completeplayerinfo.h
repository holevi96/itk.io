#ifndef COMPLETEPLAYERINFO_H
#define COMPLETEPLAYERINFO_H
#include "globalconstants.h"
#include "design.h"
#include <QtCore>

class CompletePlayerInfo
{
public:
    CompletePlayerInfo();
    CompletePlayerInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft, long lastFireRight, long lastHitted, long lastSink, fireDirection firing, bool gettingHit, bool sinking,
                       fireDirection fireCapability, int life, int maxLife,
                       int rechargeTime, QString name, Design design);
private:
    int id;
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
    int rechargeStatus;
    int rechargeTime;
    QString name;
    Design design;
};

#endif // COMPLETEPLAYERINFO_H
