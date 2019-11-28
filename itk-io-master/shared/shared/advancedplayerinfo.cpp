#include "advancedplayerinfo.h"

AdvancedPlayerInfo::AdvancedPlayerInfo()
{

}

AdvancedPlayerInfo::AdvancedPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[2].toInt();
    this->x = pieces[3].toInt();
    this->y = pieces[4].toInt();
    this->phi = pieces[5].toInt();
    this->size = pieces[6].toInt();
   /* this->firing = serializeHelper::fireDirectionFromString(pieces[7]);
    this->gettingHit = (pieces[8]=="1")?true:false;
    this->sinking = (pieces[9]=="1")?true:false;*/
    this->lastFireLeft = pieces[7].toInt();
    this->lastFireRight = pieces[8].toInt();
    this->lastHitted = pieces[9].toInt();
    this->lastSink = pieces[10].toInt();
}

AdvancedPlayerInfo::~AdvancedPlayerInfo()
{

}

AdvancedPlayerInfo::AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, long lastFireLeft, long lastFireRight, long lastHitted, long lastSink):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size),lastFireLeft(lastFireLeft),lastFireRight(lastFireRight),lastHitted(lastHitted),lastSink(lastSink)
{

}
/*AdvancedPlayerInfo::AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size),firing(firing),gettingHit(gettingHit),sinking(sinking)
{

}*/

QString AdvancedPlayerInfo::getSerializedClass(){
    QString code = "A";
    QString sid = QString::number(id);
    QString sx = QString::number(x);
    QString sy = QString::number(y);
    QString sphi = QString::number(phi);
    QString ssize = QString::number(size);
    /*QString sfiring = serializeHelper::fireDirectionToString(firing);
    QString sgethit = (gettingHit==true)?"1":"0";
    QString ssink = (sinking==true)?"1":"0";*/
    QString lf = QString::number(lastFireLeft);
    QString rf = QString::number(lastFireRight);
    QString lh = QString::number(lastHitted);
    QString ls = QString::number(lastSink);

    QString message = code.append("|").append(sid).append("|").append(sx).append("|").append(sy).append("|").append(sphi).append("|").append(ssize).append("|").append(lf).append("|").append(rf).append("|").append(lh).append("|").append(ls);
    return message;

}


