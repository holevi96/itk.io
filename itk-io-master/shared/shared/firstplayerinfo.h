#ifndef FIRSTPLAYERINFO_H
#define FIRSTPLAYERINFO_H
#include "playerinfo.h"
#include "serializable.h"
#include "design.h"

class FirstPlayerInfo : public Playerinfo
{
public:
    FirstPlayerInfo(QString serial);
    virtual ~FirstPlayerInfo();
    FirstPlayerInfo(int id, QString name,Design* d);
    QString getSerializedClass() override;
    void setClassBySerializedString(QString serial);
    QString getName() override;
    QString getPlayerName();
    Design* getDesign() const;

private:
    Design* design;
    QString name;

};



#endif // FIRSTPLAYERINFO_H
