#include "servernetcommunication.h"
#include <QTcpSocket>
#include "mainwindow.h"
#include <../shared/shared/serverinfo.cpp>
serverNetCommunication::serverNetCommunication(MainWindow* pHelloServer,QObject *parent) : QTcpServer(parent)
{
    m_pHelloWindow=pHelloServer;
    gc = new GameCore();
    sInfo = new ServerInfo(1024,769,0.1);
}

void serverNetCommunication::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    m_pHelloWindow->addMessage("New client from: "+client->peerAddress().toString());

    //TODO: ID generálása (most a tömb mérete az ID, de ez nem túl jó
    gc->playerJoined(clients.size(),"ez_egy_nev");

    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void serverNetCommunication::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QString line = QString::fromUtf8(client->readLine()).trimmed();
    qDebug() << "Read line:" << line;
    m_pHelloWindow->addMessage(line);
    if(line.contains("CJS")){
        //TODO: check if user can join
        if(true){
            ServerInfo* s = new ServerInfo(gc->getEnvironment().xSize,gc->getEnvironment().ySize,gc->getEnvironment().stepSize);
            QString l = s->getSerializedClass();
            client->write("SJI|"+l.toUtf8());
        }

    }

}

void serverNetCommunication::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();

    clients.remove(client);
}
