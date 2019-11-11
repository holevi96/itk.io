#ifndef BORINGPLAYERINFO_H
#define BORINGPLAYERINFO_H
#include "playerinfo.h"
#include "serializable.h"
class Playerinfo;
class BoringPlayerInfo : public Playerinfo
{
public:
    BoringPlayerInfo();
    BoringPlayerInfo(int id, int score, int x, int y, int phi, int size);
    QString getSerializedClass();
    void setClassBySerializedString(QString serial);
private:
    int score;
    int x; int y; int phi; int size;

};

#endif // BORINGPLAYERINFO_H
