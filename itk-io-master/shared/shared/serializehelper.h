#ifndef SERIALIZEHELPER_H
#define SERIALIZEHELPER_H
#include <QtCore>
#include "globalconstants.h"
#include <list>
class Playerinfo;
using namespace std;
class serializeHelper

{
public:
    serializeHelper();
    static QString verticalDirectionToString(verticalDirection e);
    static QString turnDirectionToString(turnDirection e);
    static QString fireDirectionToString(fireDirection e);
    static verticalDirection verticalDirectionFromString(QString str);
    static turnDirection turnDirectionFromString(QString str);
    static fireDirection fireDirectionFromString(QString str);
    static QString playerInfoListToString(std::list<Playerinfo*> plist);
    static list<Playerinfo*> playerInfoListFromString(QString str);
};

#endif // SERIALIZEHELPER_H
