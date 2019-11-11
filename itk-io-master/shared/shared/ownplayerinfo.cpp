#include "ownplayerinfo.h"

OwnPlayerInfo::OwnPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[2].toInt();
    this->x = pieces[3].toInt();
    this->y = pieces[4].toInt();
    this->phi = pieces[5].toInt();
    this->size = pieces[6].toInt();
    this->firing = serializeHelper::fireDirectionFromString(pieces[7]);
    this->gettingHit = (pieces[8]=="1")?true:false;
    this->sinking = (pieces[9]=="1")?true:false;

    this->fireCapability = serializeHelper::fireDirectionFromString(pieces[10]);
    this->life = pieces[11].toInt();
    this->maxLife = pieces[12].toInt();
    this->rechargeStatus = pieces[13].toInt();
    this->rechargeTime = pieces[14].toInt();
}

OwnPlayerInfo::~OwnPlayerInfo()
{

}
OwnPlayerInfo::OwnPlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking,fireDirection fireCapability, int life, int maxLife, int rechargeStatus, int rechargeTime):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size),firing(firing),gettingHit(gettingHit),sinking(sinking),fireCapability(fireCapability),life(life),maxLife(maxLife),rechargeStatus(rechargeStatus),rechargeTime(rechargeTime)
{
    //this->id = id;
}

QString OwnPlayerInfo::getSerializedClass(){
    QString code = "O";
    QString sid = QString::number(id);
    QString sx = QString::number(x);
    QString sy = QString::number(y);
    QString sphi = QString::number(phi);
    QString ssize = QString::number(size);
    QString sfiring = serializeHelper::fireDirectionToString(firing);
    QString sgethit = (gettingHit==true)?"1":"0";
    QString ssink = (sinking==true)?"1":"0";

    QString scap = serializeHelper::fireDirectionToString(fireCapability);
    QString slife = QString::number(life);
    QString smaxlife = QString::number(maxLife);
    QString srechages = QString::number(rechargeStatus);
    QString srecharget = QString::number(rechargeTime);


    QString message = code.append("|").append(sid).append("|").append(sx).append("|").append(sy).append("|").append(sphi).append("|").append(ssize).append("|").append(sfiring).append("|").append(sgethit).append("|").append(ssink).append("|")
            .append(scap).append("|").append(slife).append("|")
            .append(smaxlife).append("|").append(srechages).append("|")
            .append(rechargeTime);
    return message;

}