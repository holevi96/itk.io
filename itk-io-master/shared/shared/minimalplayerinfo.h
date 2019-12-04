#ifndef MINIMALPLAYERINFO_H
#define MINIMALPLAYERINFO_H
#include "playerinfo.h"
#include "serializable.h"

class MinimalPlayerInfo : public Playerinfo
{
public:
    MinimalPlayerInfo(QString serial);
    virtual ~MinimalPlayerInfo() override;
    MinimalPlayerInfo(int id, int score,long lastFireLeft,long lastFireRight, long lastHitted, long lastSink);
    QString getSerializedClass() override;
    QString getName() override;
    int getScore() const;

    long getLastFireLeft() const;

    long getLastFireRight() const;

    long getLastHitted() const;

    long getLastSink() const;

private:
    int score;

    long lastFireLeft;
    long lastFireRight;
    long lastHitted;
    long lastSink;
};

#endif // MINIMALPLAYERINFO_H
