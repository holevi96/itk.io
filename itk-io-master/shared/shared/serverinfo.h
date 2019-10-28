#ifndef SERVERINFO_H
#define SERVERINFO_H
#include <QTcpSocket>
#include <QDataStream>
class ServerInfo
{
public:
    ServerInfo(int sizeX,int sizeY,float stepSize);
    int sizeX;
    int sizeY;
    float stepSize;
    friend QDataStream& operator<<(QDataStream &stream,  const ServerInfo* &c);
};

#endif // SERVERINFO_H
