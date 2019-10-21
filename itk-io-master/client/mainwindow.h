#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

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
    void connectButtonPushed(QString ip,quint16 port);

private slots:
    void on_actionConnect_triggered();
    void displayError(QAbstractSocket::SocketError socketError);
    void readyRead();
private:
    Ui::MainWindow *ui;
    bool connected = false;
     QTcpSocket *m_pClientSocket;
};
#endif // MAINWINDOW_H
