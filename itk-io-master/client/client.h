#ifndef CLIENT_H
#define CLIENT_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <list>
#include "../shared/shared/serializable.h"
#include "../shared/shared/serverinfo.h"
#include "../shared/shared/playerinfo.h"
#include "../shared/shared/advancedplayerinfo.h"
#include "../shared/shared/completeplayerinfo.h"
#include "../shared/shared/minimalplayerinfo.h"
#include "../shared/shared/ownplayerinfo.h"
#include "../shared/shared/firstplayerinfo.h"

/*
 *    TODO
*/
using namespace std;
class MainWindow;

class Client : public QObject
{
    Q_OBJECT
public:
    Client(MainWindow *w);

    void pressedForwardButton();
    void pressedBackwardButton();
    void pressedTurnLeftButton();
    void pressedTurnRightButton();
    void pressedFireLeftButton();
    void pressedFireRightButton();

    void releasedForwardButton();
    void releasedBackwardButton();
    void releasedTurnLeftButton();
    void releasedTurnRightButton();
    void releasedFireLeftButton();
    void releasedFireRightButton();

    void clickedQuitGameButton();
    void clickedQuitServerButton();
    void clickedJoinGameButton();

    void clickedJoinServerButton(QString name, QString ipAddress, int portNum);

    ServerInfo* getServerInfo();
    list<CompletePlayerInfo*> getPlayerInfoList();



private:
    MainWindow *window;
   // Serializable* serializeHelper = new Serializable();
    bool connected = false;
    QTcpSocket *m_pClientSocket;
    ServerInfo* serverInfo;
    list<CompletePlayerInfo*> playerInfos;
private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void readyRead();
};

#endif // CLIENT_H
