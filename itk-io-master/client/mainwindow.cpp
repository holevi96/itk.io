#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_connectdialog.h"
#include "connectdialog.h"
#include "connecttogame.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //elrejtjük a connect to game menüpontot.
    ui->menuConnect->actions().at(1)->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_triggered()
{
    m_pClientSocket = new QTcpSocket(this);
    ConnectDialog c(this);
    c.setModal(true);
    c.exec();
}

void MainWindow::connected_to_server(){
    qDebug() << "Connected to server.";
    ui->menuConnect->actions().at(0)->setEnabled(false);
     ui->menuConnect->actions().at(1)->setEnabled(true);
}


void MainWindow::connectButtonPushed(QString ip,quint16 port){
    qDebug() << ip;
    m_pClientSocket->connectToHost(ip,port);
    if(m_pClientSocket->isOpen()){
        connected_to_server();
    }
    //connect the socket error to our error
    connect(m_pClientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(m_pClientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}
void MainWindow::readyRead(){
    QTcpSocket *server = (QTcpSocket*)sender();
    QString line = QString::fromUtf8(server->readLine()).trimmed();
    qDebug() <<  "Returned message: " << line;
}

void MainWindow::displayError ( QAbstractSocket::SocketError socketError )
{
    switch (socketError) {
         case QAbstractSocket::RemoteHostClosedError:
             break;
         case QAbstractSocket::HostNotFoundError:
             QMessageBox::information(this, tr("Fortune Client"),
                                      tr("The host was not found. Please check the "
                                         "host name and port settings."));
             break;
         case QAbstractSocket::ConnectionRefusedError:
             QMessageBox::information(this, tr("Fortune Client"),
                                      tr("The connection was refused by the peer. "
                                         "Make sure the fortune server is running, "
                                         "and check that the host name and port "
                                         "settings are correct."));
             break;
         default:
             QMessageBox::information(this, tr("Fortune Client"),
                                      tr("The following error occurred: %1.")
                                      .arg(m_pClientSocket->errorString()));
         }


}

void MainWindow::on_actionConnect_to_game_triggered()
{
    connectToGame con(this);
    con.setModal(true);
    con.exec();
    //m_pClientSocket->write(QString("Name: "))
}
