#include "minimalplayerinfo.h"

MinimalPlayerInfo::MinimalPlayerInfo()
{

}

MinimalPlayerInfo::MinimalPlayerInfo(int i, int s)
{
    this->id = i;
    this->score = s;
}
QString MinimalPlayerInfo::getSerializedClass(){
    QString sid = QString::number(id);
    QString sscore = QString::number(score);

    QString message = sid.append("|").append(sscore);
    return message;

}

void MinimalPlayerInfo::setClassBySerializedString(QString serial){
    QStringList pieces = serial.split("|");
    this->id = pieces[1].toInt();
    this->score = pieces[2].toInt();
}

