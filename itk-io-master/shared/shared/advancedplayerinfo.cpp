#include "advancedplayerinfo.h"

AdvancedPlayerInfo::AdvancedPlayerInfo()
{

}
AdvancedPlayerInfo::AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking):
score(score),x(x),y(y),phi(phi),size(size),firing(firing),gettingHit(gettingHit),sinking(sinking)
{
    this->id = id;
}

QString AdvancedPlayerInfo::getSerializedClass(){
    QString sid = QString::number(id);
    QString sx = QString::number(x);
    QString sy = QString::number(y);
    QString sphi = QString::number(phi);
    QString ssize = QString::number(size);
    QString sfiring = fireDirectionToString(firing);
    QString sgethit = (gettingHit==true)?"1":"0";
    QString ssink = (sinking==true)?"1":"0";

    QString message = sid.append("|").append(sx).append("|").append(sy).append("|").append(sphi).append("|").append(ssize).append("|").append(sfiring).append("|").append(sgethit).append("|").append(ssink);
    return message;

}

void AdvancedPlayerInfo::setClassBySerializedString(QString serial){
    QStringList pieces = serial.split("|");
    this->id = pieces[1].toInt();
    this->x = pieces[2].toInt();
    this->y = pieces[3].toInt();
    this->phi = pieces[4].toInt();
    this->size = pieces[5].toInt();
    this->firing = fireDirectionFromString(pieces[6]);
    this->gettingHit = (pieces[7]=="1")?true:false;
    this->sinking = (pieces[8]=="1")?true:false;
}
