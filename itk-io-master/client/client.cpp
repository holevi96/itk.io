#include "client.h"
#include "../shared/shared/serializehelper.cpp"
#include "../shared/shared/serverinfo.cpp"
/*
 *    TODO
*/

Client::Client(MainWindow *w):window(w)
{

}
ServerInfo* Client::getServerInfo(){
   return dynamic_cast<ServerInfo*>(this->serverInfo);
}
list<CompletePlayerInfo*> Client::getPlayerInfoList(){

    // get a list of values
    list<CompletePlayerInfo*> my_vals;
    transform(playerInfos.begin(), playerInfos.end(), back_inserter(my_vals), get_second() );
    return my_vals;

}

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
         m_pClientSocket->write("CJS|"+name.toUtf8());
    }
    //connect the socket error to our error
    connect(m_pClientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(m_pClientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));


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

    if(line.contains("SRJ")){
        //server refused to join
        window->connectNotSuccessful("Refused to join. Try an other name.");
    }
    if(line.contains("SJI")){
        //Joined to server successfully - receiving first time informations
        ServerInfo* s = new ServerInfo(line);
        this->serverInfo = s;
       // serverInfo->setClassBySerializedString(line);
        window->joinedSuccessful();

    }
    if(line.contains("SOI")){
       list<Playerinfo*> newinfos = serializeHelper::playerInfoListFromString(line);
       /*TODO: update playerinfos list with the new playerinfos arrived*/

    }

}