#include "firstplayerinfo.h"

FirstPlayerInfo::FirstPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    this->id = pieces[2].toInt();
    this->name = pieces[3];
    Design d(pieces[4]);
    this->design = d;
}

FirstPlayerInfo::~FirstPlayerInfo()
{

}
FirstPlayerInfo::FirstPlayerInfo(int id, int name,Design d):
Playerinfo(id),design(d),name(name)
{

};
QString FirstPlayerInfo::getSerializedClass(){
    QString code = "F";
    QString sid = QString::number(id);
    QString sname = name;
    QString sd = design.getSerializedClass();


    QString message = code.append("|").append(sid).append("|").append(sname).append("|").append(sd);
    return message;

}

