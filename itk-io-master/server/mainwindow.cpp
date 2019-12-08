#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server/sn/servernetcommunication.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sentDataFreq = 100;
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


void MainWindow::on_pauseStart_clicked()
{
    if(m_pBoxServer->m_timer->isActive()){
       m_pBoxServer->m_timer->stop();
    }else{
        m_pBoxServer->m_timer->start(1000);
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    this->sentDataFreq = arg1;
}


