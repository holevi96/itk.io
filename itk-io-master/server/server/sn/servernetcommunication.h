#ifndef SERVERNETCOMMUNICATION_H
#define SERVERNETCOMMUNICATION_H

#include <QTcpServer>
#include "../core/gamecore.h"

#include "mainwindow.h"
#include "serializable.h"
#include "serializehelper.h"
#include "serverinfo.h"
#include "player.h"
#include <QTimer>

class ServerInfo;
class MainWindow;
class serverNetCommunication : public QTcpServer
{
    Q_OBJECT
public:
    serverNetCommunication(MainWindow* pHelloServer,QObject *parent=0);
    MainWindow* m_pHelloWindow;
    GameCore* gc;

private slots:
    void readyRead();
    void disconnected();
    void sendPlayers();

protected:
    void incomingConnection(int socketfd);
    void incomingConnection(long long socketfd);

private:
    QSet<QTcpSocket*> clients;
    ServerInfo* sInfo;
    int connectionsNum = 0;
    bool isNameExisting(QString name);
    map<QTcpSocket*, Player*> players;
    QTimer *m_timer;
};

#endif // SERVERNETCOMMUNICATION_H
