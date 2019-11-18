#ifndef ADVANCEDPLAYERINFO_H
#define ADVANCEDPLAYERINFO_H
#include "playerinfo.h"

#include "serializehelper.h"
#include "globalconstants.h"

class AdvancedPlayerInfo : public Playerinfo
{
public:
    AdvancedPlayerInfo();
    AdvancedPlayerInfo(QString string);
    virtual ~AdvancedPlayerInfo();
    AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking);
    QString getSerializedClass();
private:
    int score;
    int x;
    int y;
    int phi;
    int size;
    fireDirection firing;
    bool gettingHit;
    bool sinking;

};

#endif // ADVANCEDPLAYERINFO_H
