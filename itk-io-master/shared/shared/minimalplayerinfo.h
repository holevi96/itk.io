#ifndef MINIMALPLAYERINFO_H
#define MINIMALPLAYERINFO_H
#include "playerinfo.h"
#include "serializable.h"

class MinimalPlayerInfo : public Playerinfo
{
public:
    MinimalPlayerInfo();
    MinimalPlayerInfo(int name, int score);
    QString getSerializedClass();
    void setClassBySerializedString(QString serial);
private:
    int score;
};

#endif // MINIMALPLAYERINFO_H
