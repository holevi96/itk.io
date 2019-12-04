#ifndef BORINGPLAYERINFO_H
#define BORINGPLAYERINFO_H
#include "playerinfo.h"

class Playerinfo;
class BoringPlayerInfo : public Playerinfo
{
public:
    BoringPlayerInfo(QString serial);
    virtual ~BoringPlayerInfo() override;
    BoringPlayerInfo(int id, int score, int x, int y, int phi, int size);
    QString getSerializedClass() override;
    QString getName() override;
private:
    int score;
    int x; int y; int phi; int size;

};

#endif // BORINGPLAYERINFO_H
