#include "boringplayerinfo.h"

BoringPlayerInfo::BoringPlayerInfo()
{

}
BoringPlayerInfo::BoringPlayerInfo(int id, int score, int x, int y, int phi, int size):
score(score),x(x),y(y),phi(phi),size(size)
{
    this->id = id;
}
QString BoringPlayerInfo::getSerializedClass(){
    QString sid = QString::number(id);
    QString sx = QString::number(x);
    QString sy = QString::number(y);
    QString sphi = QString::number(phi);
    QString ssize = QString::number(size);


    QString message = sid.append("|").append(sx).append("|").append(sy).append("|").append(sphi).append("|").append(ssize);
    return message;

}

void BoringPlayerInfo::setClassBySerializedString(QString serial){
    QStringList pieces = serial.split("|");
    this->id = pieces[1].toInt();
    this->x = pieces[2].toInt();
    this->y = pieces[3].toInt();
    this->phi = pieces[4].toInt();
    this->size = pieces[5].toInt();
}
