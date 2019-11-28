#ifndef PLAYER_H
#define PLAYER_H
#include <QtCore>
#include <QTcpServer>

class Player
{
public:
    Player(int id);
    int id;
    QString name;
    void setName(QString name);
};

#endif // PLAYER_H
