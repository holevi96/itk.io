#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server/sn/servernetcommunication.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pBoxServer;
}

void MainWindow::on_pushButtonStart_clicked()
{

   m_pBoxServer= new serverNetCommunication(this);


    bool success = m_pBoxServer->listen(QHostAddress::Any, quint16(ui->textEditPort->toPlainText().toInt()));
    if(!success)
    {
        addMessage("Server failed...");

    }
    else
    {
        addMessage("Server Started...");
    }
}

void MainWindow::addMessage(QString Msg)
{
    ui->textEditStatus->setText(Msg);

}

