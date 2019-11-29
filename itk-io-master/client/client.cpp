#include "client.h"

/*
 *    TODO
*/

Client::Client(MainWindow *w):window(w)
{
    qDebug()<<"client created";
}
/*ServerInfo* Client::getServerInfo(){
   return dynamic_cast<ServerInfo*>(this->serverInfo);
}
list<CompletePlayerInfo*> Client::getPlayerInfoList(){

   return playerInfos;
}*/


void Client::pressedForwardButton(){
   m_pClientSocket->write("CSP|"+serializeHelper::verticalDirectionToString(verticalDirection::FORWARD).toUtf8());
};
void Client::pressedBackwardButton(){
    m_pClientSocket->write("CSP|"+serializeHelper::verticalDirectionToString(verticalDirection::BACKWARD).toUtf8());

};
void Client::pressedTurnLeftButton(){
    m_pClientSocket->write("CDI|"+serializeHelper::turnDirectionToString(turnDirection::LEFT).toUtf8());
};
void Client::pressedTurnRightButton(){
    m_pClientSocket->write("CDI|"+serializeHelper::turnDirectionToString(turnDirection::RIGHT).toUtf8());
}
void Client::pressedFireLeftButton(){
    m_pClientSocket->write("CFI|"+serializeHelper::fireDirectionToString(fireDirection::LEFT).toUtf8());
}
void Client::pressedFireRightButton(){
    m_pClientSocket->write("CFI|"+serializeHelper::fireDirectionToString(fireDirection::RIGHT).toUtf8());
}
void Client::releasedForwardButton(){
    m_pClientSocket->write("CSP|"+serializeHelper::verticalDirectionToString(verticalDirection::REST).toUtf8());
}
void Client::releasedBackwardButton(){
    m_pClientSocket->write("CSP|"+serializeHelper::verticalDirectionToString(verticalDirection::REST).toUtf8());
}
void Client::releasedTurnLeftButton(){
    m_pClientSocket->write("CDI|"+serializeHelper::turnDirectionToString(turnDirection::REST).toUtf8());
}
void Client::releasedTurnRightButton(){
    m_pClientSocket->write("CDI|"+serializeHelper::turnDirectionToString(turnDirection::REST).toUtf8());
}
void Client::releasedFireLeftButton(){
     m_pClientSocket->write("CFI|"+serializeHelper::fireDirectionToString(fireDirection::NONE).toUtf8());
}
void Client::releasedFireRightButton(){
     m_pClientSocket->write("CFI|"+serializeHelper::fireDirectionToString(fireDirection::NONE).toUtf8());
}

void Client::clickedQuitGameButton(){
    m_pClientSocket->write("CQG");
}
void Client::clickedQuitServerButton(){

}
void Client::clickedJoinGameButton(){
    m_pClientSocket->write("CJG");
}

void Client::clickedJoinServerButton(QString name, QString ipAddress, int portNum){
    m_pClientSocket = new QTcpSocket();
    m_pClientSocket->connectToHost(ipAddress,quint16(portNum));
    if(m_pClientSocket->isOpen()){
        qDebug()<<"1";
         m_pClientSocket->write("CJS|"+name.toUtf8());
    }
    //connect the socket error to our error

    qDebug()<<"2";
    connect(m_pClientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    qDebug()<<"3";
    connect(m_pClientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug()<<"4";

}
void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
         case QAbstractSocket::RemoteHostClosedError:
            window->fatalError("Remote Host closed");
             break;
         case QAbstractSocket::HostNotFoundError:
             window->networkErrorMessage("The host was not found. Please check the host name and port settings.");
             break;
         case QAbstractSocket::ConnectionRefusedError:
             window->networkErrorMessage("The connection was refused by the peer. Make sure the server is running and check that the host name and port settings are correct.");
             break;
         default:
             window->networkErrorMessage(m_pClientSocket->errorString());
         }
}


void Client::readyRead(){
    QTcpSocket *server = (QTcpSocket*)sender();
    QString line = QString::fromUtf8(server->readLine()).trimmed();
    qDebug()<<line;
    qDebug()<<"readyRead";

    if(line.contains("SRJ")){
        //server refused to join
        window->connectNotSuccessful("Refused to join. Try an other name.");
    }
    else if(line.contains("SJI")){
        //Joined to server successfully - receiving first time informations
        this->serverInfo = new ServerInfo(line);
        qDebug()<<this->serverInfo->sizeX;
        window->joinedSuccessful();

    }
    else if(line.contains("SOI")){
       list<Playerinfo*> newinfos = serializeHelper::playerInfoListFromString(line);

       list<CompletePlayerInfo*> compInfos;
        for(auto p : newinfos){
            qDebug()<<typeid(p).name();
            if(typeid(p).name() == "MinimalPlayerInfo"){

            }
        }
       /*TODO: update playerinfos list with the new playerinfos arrived*/
        data_changed();
    }
    else{
        /*TODO*/

        qDebug()<<"invalid message ( "+line+" )";
    }

}
