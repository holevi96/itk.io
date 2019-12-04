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
    m_pHelloWindow->addMessage("New client from: "+client->peerAddress().toString());

    qDebug()<<"incoming connection";
    Player* p = new Player(connectionsNum);
    players.insert(std::pair<QTcpSocket*, Player*>(client,p));
    connectionsNum++;


    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));

    client->write("startttt");

    if(connectionsNum == 1){
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &serverNetCommunication::sendPlayers);
        m_timer->start(1000);
    }

}
void serverNetCommunication::incomingConnection(long long socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);
    //m_pHelloWindow->addMessage("New client from: "+client->peerAddress().toString());



    connectionsNum++;


    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));

    client->write("startttt");

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &serverNetCommunication::sendPlayers);
    m_timer->start(1000);


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

            Player* p = new Player(connectionsNum);
            players.insert(std::pair<QTcpSocket*, Player*>(client,p));

            Serializable* s = new ServerInfo(gc->getEnvironment().xSize,gc->getEnvironment().ySize,gc->getEnvironment().stepSize);
            QString l = s->getSerializedClass();
            client->write("SJI|"+l.toUtf8()+"\n");

            Design* d = new Design();
            FirstPlayerInfo* f = new FirstPlayerInfo(ID,name,d);
            client->write(f->getSerializedClass().toUtf8()+"\n");
            gc->playerJoined(ID,name.toStdString());
            delete p;
            delete d;
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
   //TODO: remove client from players map.

}

void serverNetCommunication::sendPlayers()
{
    map<QTcpSocket*, Player*>::iterator it;


    for ( it = players.begin(); it != players.end(); it++ )
    {
        list<Playerinfo*> plist;
        int ownID = it->second->id;
        OwnPlayerInfo* o = new OwnPlayerInfo(ownID,gc->getScore(ownID),gc->getX(ownID),gc->getY(ownID),
                                            gc->getPhi(ownID),gc->getSize(ownID),gc->lastFireLeft(ownID),
                                            gc->lastFireRight(ownID),gc->lastHitGot(ownID),gc->lastStartedSink(ownID),
                                            gc->getFireCapability(ownID),gc->getLife(ownID),
                                            gc->getMaxLife(ownID),gc->getRechargeTime(ownID));

        plist.push_back(o);
        map<QTcpSocket*, Player*>::iterator it2;
        for ( it2 = players.begin(); it2 != players.end(); it2++ )
        {
            int ID = it2->second->id;
            if(ID != ownID){
                //TODO: ha a játékos közelebb van mint egy treshold, vagy nem rég lőtt, akkor advancedplayerinfo
                if(true){
                    AdvancedPlayerInfo* a = new AdvancedPlayerInfo(ID,gc->getScore(ID),gc->getX(ID),gc->getY(ID),
                                                                   gc->getPhi(ID),gc->getSize(ID),gc->lastFireLeft(ID),
                                                                   gc->lastFireRight(ID),gc->lastHitGot(ID),gc->lastStartedSink(ID));


                    //AdvancedPlayerInfo* a = new AdvancedPlayerInfo(ID,1,0,0,0,0,0,0,0,0);
                    plist.push_back(a);
                }else{
                    //különben minimalplayerinfo
                    MinimalPlayerInfo* m = new MinimalPlayerInfo(ID,gc->getScore(ID),gc->lastFireLeft(ID),
                                                                 gc->lastFireRight(ID),gc->lastHitGot(ID),gc->lastStartedSink(ID));
                    plist.push_back(m);
                }

            }
        }
        //itt kéne elküldeni az adott embernek az elkészült tömböt.
        QString serialized = serializeHelper::playerInfoListToString(plist);

        it->first->write(serialized.toUtf8()+"\n");

    }
}
