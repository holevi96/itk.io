#ifndef FIRSTPLAYERINFO_H
#define FIRSTPLAYERINFO_H
#include "playerinfo.h"
#include "design.h"

class FirstPlayerInfo : public Playerinfo
{
public:
    FirstPlayerInfo();
    FirstPlayerInfo(int id, int name,Design d);
    QString getSerializedClass();
    void setClassBySerializedString(QString serial);
private:
    Design design;
    QString name;

};

#endif // FIRSTPLAYERINFO_H
