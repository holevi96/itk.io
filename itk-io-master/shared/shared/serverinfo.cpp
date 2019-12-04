#include "serverinfo.h"

ServerInfo::ServerInfo()
{

}

ServerInfo::ServerInfo(int sizeX,int sizeY,float stepSize):
    sizeX(sizeX),sizeY(sizeY),stepSize(stepSize)
{

}

ServerInfo::ServerInfo(QString s)
{
    QStringList pieces = s.split("|");
    this->sizeX = pieces[1].toInt();
    this->sizeY = pieces[2].toInt();
    this->stepSize = pieces[3].toInt();
}

ServerInfo::~ServerInfo()
{

}


QString ServerInfo::getSerializedClass(){
    QString sx = QString::number(sizeX);
    QString sy = QString::number(sizeY);
    QString sf = QString::number(stepSize);


    QString message = sx.append("|").append(sy).append("|").append(sf);
    return message;
}

QString ServerInfo::getName()
{
 return "ServerInfo";
}

