#ifndef CLIENT_H
#define CLIENT_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QTcpSocket>
#include <list>

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
typedef map<unsigned, CompletePlayerInfo*> MyMap;
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
   // list<CompletePlayerInfo*> playerInfos;

    MyMap playerInfos;
private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void readyRead();

signals:
    void data_changed();
};

struct get_second : public std::unary_function<MyMap::value_type, CompletePlayerInfo*>
{
    CompletePlayerInfo* operator()(const MyMap::value_type& value) const
    {
        return value.second;
    }
};
#endif // CLIENT_H
