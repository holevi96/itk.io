#ifndef MINIMALPLAYERINFO_H
#define MINIMALPLAYERINFO_H
#include "playerinfo.h"
#include "serializable.h"

class MinimalPlayerInfo : public Playerinfo
{
public:
    MinimalPlayerInfo(QString serial);
    virtual ~MinimalPlayerInfo();
    MinimalPlayerInfo(int id, int score);
    QString getSerializedClass();
private:
    int score;
};

#endif // MINIMALPLAYERINFO_H
