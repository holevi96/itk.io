#include "minimalplayerinfo.h"

MinimalPlayerInfo::MinimalPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[1].toInt();
    this->score = pieces[2].toInt();

    this->lastFireLeft = pieces[3].toInt();
    this->lastFireRight = pieces[4].toInt();
    this->lastHitted = pieces[5].toInt();
    this->lastSink = pieces[6].toInt();

}

MinimalPlayerInfo::~MinimalPlayerInfo()
{

}

MinimalPlayerInfo::MinimalPlayerInfo(int i, int s,long lastFireLeft,long lastFireRight, long lastHitted, long lastSink):
    Playerinfo(i),score(s),lastFireLeft(lastFireLeft),lastFireRight(lastFireRight),lastHitted(lastHitted),lastSink(lastSink)

{
}
QString MinimalPlayerInfo::getSerializedClass(){
    QString code = "M";
    QString sid = QString::number(id);
    QString sscore = QString::number(score);
    QString lf = QString::number(lastFireLeft);
    QString rf = QString::number(lastFireRight);
    QString lh = QString::number(lastHitted);
    QString ls = QString::number(lastSink);

    QString message = code.append("|").append(sid).append("|").append(sscore).append(lf).append("|").append(rf).append("|").append(lh).append("|").append(ls);
    return message;

}

QString MinimalPlayerInfo::getName()
{
 return "M";
}

int MinimalPlayerInfo::getScore() const
{
    return score;
}

long MinimalPlayerInfo::getLastFireLeft() const
{
    return lastFireLeft;
}

long MinimalPlayerInfo::getLastFireRight() const
{
    return lastFireRight;
}

long MinimalPlayerInfo::getLastHitted() const
{
    return lastHitted;
}

long MinimalPlayerInfo::getLastSink() const
{
    return lastSink;
}

