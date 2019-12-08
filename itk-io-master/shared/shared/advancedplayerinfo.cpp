#include "advancedplayerinfo.h"

AdvancedPlayerInfo::AdvancedPlayerInfo()
{

}

AdvancedPlayerInfo::AdvancedPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[1].toInt();
    this->score = pieces[2].toInt();
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
    this->life = pieces[11].toInt();
    this->maxLife = pieces[12].toInt();
}

AdvancedPlayerInfo::~AdvancedPlayerInfo()
{

}

AdvancedPlayerInfo::AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, long lastFireLeft, long lastFireRight, long lastHitted, long lastSink,int life, int maxLife):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size),lastFireLeft(lastFireLeft),lastFireRight(lastFireRight),lastHitted(lastHitted),lastSink(lastSink),life(life),maxLife(maxLife)
{

}
/*AdvancedPlayerInfo::AdvancedPlayerInfo(int id, int score, int x, int y, int phi, int size, fireDirection firing, bool gettingHit, bool sinking):
Playerinfo(id),score(score),x(x),y(y),phi(phi),size(size),firing(firing),gettingHit(gettingHit),sinking(sinking)
{

}*/

QString AdvancedPlayerInfo::getSerializedClass(){
    QString code = "A";
    QString sid = QString::number(id);
     QString sscore = QString::number(score);
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
    QString slife = QString::number(life);
    QString smaxlife = QString::number(maxLife);
    QString message = code.append("|").append(sid).append("|").append(sscore).append("|").append(sx).append("|").append(sy).append("|")
            .append(sphi).append("|").append(ssize).append("|")
            .append(lf).append("|").append(rf).append("|")
            .append(lh).append("|").append(ls).append("|").append(slife).append("|")
            .append(smaxlife);
    return message;

}

QString AdvancedPlayerInfo::getName()
{
    return "A";
}

int AdvancedPlayerInfo::getScore() const
{
    return score;
}

int AdvancedPlayerInfo::getX() const
{
    return x;
}

int AdvancedPlayerInfo::getY() const
{
    return y;
}

int AdvancedPlayerInfo::getSize() const
{
    return size;
}

int AdvancedPlayerInfo::getPhi() const
{
    return phi;
}

long AdvancedPlayerInfo::getLastFireLeft() const
{
    return lastFireLeft;
}

long AdvancedPlayerInfo::getLastFireRight() const
{
    return lastFireRight;
}

long AdvancedPlayerInfo::getLastHitted() const
{
    return lastHitted;
}

long AdvancedPlayerInfo::getLastSink() const
{
    return lastSink;
}

int AdvancedPlayerInfo::getLife() const
{
    return life;
}

int AdvancedPlayerInfo::getMaxLife() const
{
    return maxLife;
}


