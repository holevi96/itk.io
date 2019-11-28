#include "boringplayerinfo.h"

BoringPlayerInfo::BoringPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[2].toInt();
    this->x = pieces[3].toInt();
    this->y = pieces[4].toInt();
    this->phi = pieces[5].toInt();
    this->size = pieces[6].toInt();
}

BoringPlayerInfo::~BoringPlayerInfo()
{

}
BoringPlayerInfo::BoringPlayerInfo(int id, int score, int x, int y, int phi, int size):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size)
{

}
QString BoringPlayerInfo::getSerializedClass(){
    QString code = "B";
    QString sid = QString::number(id);
    QString sx = QString::number(x);
    QString sy = QString::number(y);
    QString sphi = QString::number(phi);
    QString ssize = QString::number(size);


    QString message = code.append("|").append(sid).append("|").append(sx).append("|").append(sy).append("|").append(sphi).append("|").append(ssize);
    return message;

}

