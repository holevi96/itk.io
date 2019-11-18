#ifndef SERVERNETCOMMUNICATION_H
#define SERVERNETCOMMUNICATION_H

#include <QTcpServer>
#include "../core/gamecore.h"

#include "mainwindow.h"
#include "serializable.h"
#include "serverinfo.h"

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

protected:
    void incomingConnection(int socketfd);

private:
    QSet<QTcpSocket*> clients;
    ServerInfo* sInfo;
};

#endif // SERVERNETCOMMUNICATION_H
