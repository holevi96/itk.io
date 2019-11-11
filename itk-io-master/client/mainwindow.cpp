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

void MainWindow::joinedSuccessful()
{
    qDebug()<<"successfully connected";
    if(state==MainWindow::GUIState::WAITING_FOR_CONNECTION){
        ingameView=new IngameView(this);                    //TODO
        setCentralWidget(ingameView);                       //TODO
        delete connectingToServer;
        connectingToServer=nullptr;
        state=MainWindow::GUIState::INGAME;                 //TODO
    }
}

void MainWindow::connectNotSuccessful(QString errorMessage)
{
    fatalError(errorMessage,"Connection Error");
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::fatalError(QString errorMessage,QString title)
{
    QMessageBox messageBox(QMessageBox::Critical,title,errorMessage,QMessageBox::Ok,this);
    messageBox.exec();

    if(ingameView!=nullptr){
        delete ingameView;
    }
    ingameView=nullptr;

    if(ingameMenu!=nullptr){
        delete ingameMenu;
    }
    ingameMenu=nullptr;

    if(connectingToServer!=nullptr){
        delete connectingToServer;
    }
    connectingToServer=nullptr;

    if(login!=nullptr){
        delete login;
    }
    login=nullptr;

    login=new LoginScreen(this);
    setCentralWidget(login);
    state=MainWindow::GUIState::LOGIN;
}

void MainWindow::connectToServer()
{
    if(state==MainWindow::GUIState::LOGIN){
        connectingToServer=new ConnectingToServerScreen(this);
        setCentralWidget(connectingToServer);

        state=MainWindow::GUIState::WAITING_FOR_CONNECTION;
        client->clickedJoinServerButton(login->getName(),login->getIP(),login->getPort());

        delete login;
        login=nullptr;
    }
    //QThread::sleep(2);              //TODO
    //joinedSuccessful();             //TODO
    //connectNotSuccessful("asd");

    //client->clickedJoinServerButton(QString name, QString ipAddress, int portNum)
}

void MainWindow::startgame()
{
    /*ingameView=new IngameView(this);
    setCentralWidget(ingameView);
    delete login;
    login=nullptr;
    qDebug()<<QString(width())+" "+QString(height());*/
}


void MainWindow::networkErrorMessage(QString errorMessage){
     /*TODO*/
};
