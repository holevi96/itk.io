#ifndef SERVERINFO_H
#define SERVERINFO_H
#include <QTcpSocket>
#include <QDataStream>

#include "serializable.h"

class ServerInfo : public Serializable
{
public:
    ServerInfo(int sizeX,int sizeY,float stepSize);
    ServerInfo();
    int sizeX;
    int sizeY;
    float stepSize;

    QString getSerializedClass();
    void setClassBySerializedString(QString s);

};

#endif // SERVERINFO_H
