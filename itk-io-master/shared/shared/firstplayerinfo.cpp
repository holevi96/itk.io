#include "firstplayerinfo.h"

FirstPlayerInfo::FirstPlayerInfo(QString serial):Playerinfo(0)
{
    QStringList pieces = serial.split("|");
    //qDebug()<<pieces.size();
    this->id = pieces[1].toInt();
    this->name = pieces[2];
    Design* d = new Design(pieces[3].toInt());
    this->design = d;
}

FirstPlayerInfo::~FirstPlayerInfo()
{

}
FirstPlayerInfo::FirstPlayerInfo(int id, QString name,Design* d):
Playerinfo(id),design(d),name(name)
{

};
QString FirstPlayerInfo::getSerializedClass(){
    QString code = "FPI";
    QString sid = QString::number(id);
    QString sname = name;
    QString sd = design->getSerializedClass();


    QString message = code.append("|").append(sid).append("|").append(sname).append("|").append(sd);
    return message;

}

QString FirstPlayerInfo::getName()
{
    return "F";
}

QString FirstPlayerInfo::getPlayerName()
{
   return name;
}

Design* FirstPlayerInfo::getDesign() const
{
    return design;
}

