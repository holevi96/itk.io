#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_connectdialog.h"
#include "connectdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_triggered()
{
    ConnectDialog c;
    c.setModal(true);
    c.exec();
}
