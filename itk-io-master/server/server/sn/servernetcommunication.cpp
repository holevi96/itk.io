#include "servernetcommunication.h"
#include <QTcpSocket>

serverNetCommunication::serverNetCommunication(MainWindow* pHelloServer,QObject *parent) : QTcpServer(parent)
{
    m_pHelloWindow=pHelloServer;
    gc = new GameCore();
    //sInfo = new ServerInfo(1024,769,0.1);
}

void serverNetCommunication::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);
    //m_pHelloWindow->addMessage("New client from: "+client->peerAddress().toString());


    Player* p = new Player(connectionsNum);
    players.insert(std::pair<QTcpSocket*, Player*>(client,p));
    connectionsNum++;

    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

bool serverNetCommunication::isNameExisting(QString name)
{
    map<QTcpSocket*, Player*>::iterator it;

    for ( it = players.begin(); it != players.end(); it++ )
    {
      if(it->second->name == name) return true;
    }
    return false;
}

void serverNetCommunication::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QString line = QString::fromUtf8(client->readLine()).trimmed();
    qDebug() << "Read line:" << line;
    m_pHelloWindow->addMessage(line);

    QStringList pieces = line.split("|");
    int ID = players.find(client)->second->id;
    if(line.contains("CJS")){


        QString name = pieces[1];
        if(!isNameExisting(name)){
            Serializable* s = new ServerInfo(gc->getEnvironment().xSize,gc->getEnvironment().ySize,gc->getEnvironment().stepSize);
            QString l = s->getSerializedClass();
            client->write("SJI|"+l.toUtf8());

            gc->playerJoined(ID,name.toStdString());
        }

    }else if(line.contains("CSP")){
        verticalDirection v = serializeHelper::verticalDirectionFromString(pieces[1]);
        gc->speed(ID, v);
    }else if(line.contains("CDI")){
        turnDirection t = serializeHelper::turnDirectionFromString(pieces[1]);
        gc->turn(ID, t);
    }else if(line.contains("CFI")){
        fireDirection f = serializeHelper::fireDirectionFromString(pieces[1]);
        gc->shoot(ID,f);
    }else if(line.contains("CQG")){
        gc->quitFromGame(ID);
    }else if(line.contains("CJG")){
        gc->joinToGame(ID);
    }

}

void serverNetCommunication::disconnected()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Client disconnected:" << client->peerAddress().toString();
    int ID = players.find(client)->second->id;
    gc->quitFromGame(ID);
    clients.remove(client);
}
