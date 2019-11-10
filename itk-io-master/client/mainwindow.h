#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>

#include "loginSreen.h"
#include "connectingToServerScreen.h"
#include "ingameScreen.h"
#include "client.h"

class Client;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum GUIState{LOGIN,WAITING_FOR_CONNECTION,GAME_MENU,INGAME};

public:
    MainWindow(int gui_width=500, int gui_height=500, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GUIState state;

    Client *client;
    ConnectingToServerScreen *connectingToSrever;
    LoginScreen* login;
    IngameView* ingameView;

public slots:
    void connectToServer();
    void startgame();


};
#endif // MAINWINDOW_H
