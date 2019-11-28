#ifndef CLIENT_H
#define CLIENT_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <list>
#include <QMutex>


#include "serializehelper.h"
#include "serializable.h"
#include "serverinfo.h"
#include "boringplayerinfo.h"
#include "playerinfo.h"
#include "advancedplayerinfo.h"
#include "completeplayerinfo.h"
#include "minimalplayerinfo.h"
#include "ownplayerinfo.h"
#include "firstplayerinfo.h"

#include "c.h"
/*
 *    TODO
*/
using namespace std;
typedef map<unsigned, CompletePlayerInfo*> MyMap;

class MainWindow;
class serializeHelper;

class Client : public QObject
{
    Q_OBJECT
public:
    Client(MainWindow *w);


public slots:
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
    void clickedLeaveGameButton();

    void clickedJoinServerButton(QString name, QString ipAddress, int portNum);




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

signals:
    void data_changed();
};


#endif // CLIENT_H
