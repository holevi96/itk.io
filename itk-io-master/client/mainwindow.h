#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "../../shared/shared/serverinfo.h"
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
    int sizeX;
    int sizeY;
    int stepSize;
};

QDataStream & operator<<(QDataStream &stream,  const ServerInfo &c);


QDataStream & operator<<(QDataStream &stream, const ServerInfo &c){
    stream << c.sizeX << c.sizeY << c.stepSize;
    return stream;
}
#endif // MAINWINDOW_H
