#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QList>
#include "../shared/shared/serializable.h"
#include "../shared/shared/serverinfo.h"
#include "../shared/shared/playerinfo.h"
#include "../shared/shared/advancedplayerinfo.h"
#include "../shared/shared/completeplayerinfo.h"
#include "../shared/shared/minimalplayerinfo.h"
#include "../shared/shared/ownplayerinfo.h"
#include "../shared/shared/firstplayerinfo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connected_to_server();
    void connectButtonPushed(QString ip,quint16 port,QString name);

private slots:
    void on_actionConnect_triggered();
    void displayError(QAbstractSocket::SocketError socketError);
    void readyRead();
    void on_actionConnect_to_game_triggered();

private:
    Ui::MainWindow *ui;
    bool connected = false;
    QTcpSocket *m_pClientSocket;
    Serializable* serverInfo;

    //QList<Playerinfo> playerList;
};

#endif // MAINWINDOW_H
