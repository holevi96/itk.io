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
                       int rechargeTime, QString name, Design* design);
    CompletePlayerInfo(int id, QString name, Design* design);
    void setMinimalinfo(int id, int score, long lastFireLeft, long lastFireRight, long lastHitted, long lastSink);
    void setAdvancedInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft, long lastFireRight, long lastHitted, long lastSink);
    void setOwnInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft, long lastFireRight,
                    long lastHitted, long lastSink,fireDirection fireCapability, int life, int maxLife,int rechargeTime);

//private:
    int id;
    int score;
    int x;
    int y;
    int phi;
    int size;           //magasság=size[pixel], szélesség=0,25*size[pixel]
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
    Design* design;
    int getId() const;
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
    int getRechargeStatus() const;
    int getRechargeTime() const;
    QString getName() const;
    Design* getDesign() const;


    void printForDebug();
};



#endif // COMPLETEPLAYERINFO_H
