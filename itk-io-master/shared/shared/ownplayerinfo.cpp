#include "ownplayerinfo.h"

OwnPlayerInfo::OwnPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[2].toInt();
    this->x = pieces[3].toInt();
    this->y = pieces[4].toInt();
    this->phi = pieces[5].toInt();
    this->size = pieces[6].toInt();
    this->lastFireLeft = pieces[7].toInt();
    this->lastFireRight = pieces[8].toInt();
    this->lastHitted = pieces[9].toInt();
    this->lastSink = pieces[10].toInt();

    this->fireCapability = serializeHelper::fireDirectionFromString(pieces[11]);
    this->life = pieces[12].toInt();
    this->maxLife = pieces[13].toInt();
    this->rechargeStatus = pieces[14].toInt();
    this->rechargeTime = pieces[15].toInt();
}

OwnPlayerInfo::~OwnPlayerInfo()
{

}
OwnPlayerInfo::OwnPlayerInfo(int id, int score, int x, int y, int phi, int size,long lastFireLeft, long lastFireRight, long lastHitted, long lastSink, fireDirection firing, bool gettingHit, bool sinking,fireDirection fireCapability, int life, int maxLife, int rechargeStatus, int rechargeTime):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size),lastFireLeft(lastFireLeft),lastFireRight(lastFireRight),lastHitted(lastHitted),lastSink(lastSink),fireCapability(fireCapability),life(life),maxLife(maxLife),rechargeStatus(rechargeStatus),rechargeTime(rechargeTime)
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
    /*QString sfiring = serializeHelper::fireDirectionToString(firing);
    QString sgethit = (gettingHit==true)?"1":"0";
    QString ssink = (sinking==true)?"1":"0";*/
    QString lf = QString::number(lastFireLeft);
    QString rf = QString::number(lastFireRight);
    QString lh = QString::number(lastHitted);
    QString ls = QString::number(lastSink);

    QString scap = serializeHelper::fireDirectionToString(fireCapability);
    QString slife = QString::number(life);
    QString smaxlife = QString::number(maxLife);
    QString srechages = QString::number(rechargeStatus);
    QString srecharget = QString::number(rechargeTime);


    QString message = code.append("|").append(sid).append("|").append(sx).append("|").append(sy).append("|").append(sphi).append("|").append(ssize)
            .append("|").append(lf).append("|").append(rf).append("|").append(lh).append("|").append(ls).append("|")
            .append(scap).append("|").append(slife).append("|")
            .append(smaxlife).append("|").append(srechages).append("|")
            .append(rechargeTime);
    return message;

}
