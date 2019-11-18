#include "minimalplayerinfo.h"

MinimalPlayerInfo::MinimalPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[2].toInt();
    this->score = pieces[3].toInt();
}

MinimalPlayerInfo::~MinimalPlayerInfo()
{

}

MinimalPlayerInfo::MinimalPlayerInfo(int i, int s):Playerinfo(i)
{
   // this->id = i;
    this->score = s;
}
QString MinimalPlayerInfo::getSerializedClass(){
    QString code = "M";
    QString sid = QString::number(id);
    QString sscore = QString::number(score);

    QString message = code.append("|").append(sid).append("|").append(sscore);
    return message;

}

