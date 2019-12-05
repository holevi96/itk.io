#ifndef PLAYER_H
#define PLAYER_H
#include <QtCore>
#include <QTcpServer>
#include "design.h"
class Player
{
public:
    Player(int id);
    int id;
    Design* d;
    QString name;
    void setName(QString name);
    Design* getDesign() const;
};

#endif // PLAYER_H
