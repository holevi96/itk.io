#ifndef BORINGPLAYERINFO_H
#define BORINGPLAYERINFO_H
#include "playerinfo.h"

class Playerinfo;
class BoringPlayerInfo : public Playerinfo
{
public:
    BoringPlayerInfo(QString serial);
    virtual ~BoringPlayerInfo();
    BoringPlayerInfo(int id, int score, int x, int y, int phi, int size);
    QString getSerializedClass();
private:
    int score;
    int x; int y; int phi; int size;

};

#endif // BORINGPLAYERINFO_H
