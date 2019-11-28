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


    int sizeX;          //enviroment height (pixel)
    int sizeY;          //enviroment width (pixel)
    float stepSize;     //simulation speed multipier

    QString getSerializedClass();

};

#endif // SERVERINFO_H
