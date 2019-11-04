#include "firstplayerinfo.h"

FirstPlayerInfo::FirstPlayerInfo()
{

}
FirstPlayerInfo::FirstPlayerInfo(int id, int name,Design d):
design(d),name(name)
{
    this->id = id;
};
QString FirstPlayerInfo::getSerializedClass(){
    QString sid = QString::number(id);
    QString sname = name;
    QString sd = design.getSerializedClass();


    QString message = sid.append("|").append(sname).append("|").append(sd);
    return message;

}

void FirstPlayerInfo::setClassBySerializedString(QString serial){
    QStringList pieces = serial.split("|");
    this->id = pieces[1].toInt();
    this->name = pieces[2];
    Design d;
    d.setClassBySerializedString(pieces[3]);
    this->design = d;
}
