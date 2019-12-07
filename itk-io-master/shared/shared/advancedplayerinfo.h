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
    virtual ~AdvancedPlayerInfo() override;
    AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, long lastFireLeft, long lastFireRight,
                       long lastHitted, long lastSink);
    QString getSerializedClass() override;
    QString getName() override;
    int getScore() const;
    int getX() const;
    int getY() const;

    int getSize() const;

    int getPhi() const;

    long getLastFireLeft() const;

    long getLastFireRight() const;

    long getLastHitted() const;

    long getLastSink() const;

private:
    int score;
    int x;
    int y;
    int phi;
    int size;

    long lastFireLeft;
    long lastFireRight;
    long lastHitted;
    long lastSink;

};

#endif // ADVANCEDPLAYERINFO_H
