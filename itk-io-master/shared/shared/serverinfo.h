#ifndef SERVERINFO_H
#define SERVERINFO_H
#include <QTcpSocket>
#include <QDataStream>

#include "serializable.h"

class ServerInfo : public Serializable
{
public:
    ServerInfo();
    ServerInfo(int sizeX,int sizeY,float stepSize);
    ServerInfo(QString string);
    virtual ~ServerInfo();


    int sizeX;
    int sizeY;
    float stepSize;

    QString getSerializedClass();

};

#endif // SERVERINFO_H
