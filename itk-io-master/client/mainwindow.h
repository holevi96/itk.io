#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QStackedWidget>


#include <QThread>                  //TODO

#include "loginSreen.h"
#include "connectingToServerScreen.h"
#include "ingameScreen.h"
#include "client.h"
#include "inGameMenu.h"
#include <list>
#include "serverinfo.h"
#include "completeplayerinfo.h"

class Client;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum GUIState{LOGIN=0,WAITING_FOR_CONNECTION=1,GAME_MENU=2,INGAME=3};

public:
    MainWindow(int gui_width=800, int gui_height=800, QWidget *parent = nullptr);
    void joinedSuccessful();
    void connectNotSuccessful(QString errorMessage);
    ~MainWindow();
    void networkErrorMessage(QString errorMessage);
    void fatalError(QString errorMessage,QString title="Fatal Error");

    Client* getClient(){return client;}

private:

    struct GameData{
        int playerId;
        ServerInfo serverInfo;
        list<CompletePlayerInfo>* completePlayerInfo;

        GameData():completePlayerInfo(nullptr){}

    };
    GameData gameData;

    Ui::MainWindow *ui;

    GUIState state;

    Client *client;

    QStackedWidget* stackedWidget;

    /*LoginScreen* login;
    ConnectingToServerScreen *connectingToServer;
    InGameMenu* ingameMenu;
    IngameView* ingameView;*/

    void setGUIState(GUIState s);
    void createGUI();


public slots:
    //void refreshPlayers();
    void setServerInfo(ServerInfo serverInfo);
    void setPlayerInfo(list<CompletePlayerInfo>* completePlayerInfo,int ownID);

    void connectToServer();
    void disconnectServer();
    void joinGame();
    void leaveGame();


};
#endif // MAINWINDOW_H
