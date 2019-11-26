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
    MainWindow(int gui_width=500, int gui_height=500, QWidget *parent = nullptr);
    void joinedSuccessful();
    void connectNotSuccessful(QString errorMessage);
    ~MainWindow();
    void networkErrorMessage(QString errorMessage);
    void fatalError(QString errorMessage,QString title="Fatal Error");

private:
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
    void setServerInfo(ServerInfo serverInfo);
    void setPlayerInfo(list<CompletePlayerInfo*> completePlayerInfo,int ownID);

public slots:
    void refreshPlayers();
private slots:
    void connectToServer();
    void joinGame();


};
#endif // MAINWINDOW_H
