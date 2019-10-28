#include "serverinfo.h"

ServerInfo::ServerInfo(int sizeX,int sizeY,float stepSize):
    sizeX(sizeX),sizeY(sizeY),stepSize(stepSize)
{

}
QDataStream& operator<<(QDataStream &stream, const ServerInfo* &c){
    stream << c->sizeX;
    stream << c->sizeY;
    stream << c->stepSize;
    return stream;
}
