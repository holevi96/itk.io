#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(int gui_width, int gui_height, QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    client=new Client(this);

    this->setFixedSize(gui_width,gui_height);
    this->statusBar()->setSizeGripEnabled(false);



    //qDebug()<<width();
    //qDebug()<<height();

/*
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsRectItem* rect=new QGraphicsRectItem();
    rect->setRect(0,0,100,100);
    scene->addItem(rect);

    QGraphicsView* view=new QGraphicsView();
    this->setCentralWidget(view);


    view->setScene(scene);
*/

    state=MainWindow::GUIState::LOGIN;

    login=new LoginScreen(this);
    this->setCentralWidget(login);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::connectToServer()
{
    state=MainWindow::GUIState::WAITING_FOR_CONNECTION;

    //client->clickedJoinServerButton(QString name, QString ipAddress, int portNum)
}

void MainWindow::startgame()
{
    ingameView=new IngameView(this);
    setCentralWidget(ingameView);
    delete login;
    login=nullptr;
    //qDebug()<<QString(width())+" "+QString(height());
}

