#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(int gui_width, int gui_height, QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    client=new Client(this);

    login=new Login(this);


    this->setFixedSize(gui_width,gui_height);
    this->statusBar()->setSizeGripEnabled(false);




/*
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsRectItem* rect=new QGraphicsRectItem();
    rect->setRect(0,0,100,100);
    scene->addItem(rect);

    QGraphicsView* view=new QGraphicsView();
    this->setCentralWidget(view);


    view->setScene(scene);
*/
    this->setCentralWidget(login);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::startgame()
{
    ingameView=new IngameView(this);
    setCentralWidget(ingameView);
    delete login;

    //qDebug()<<QString(width())+" "+QString(height());
}


void MainWindow::joinedSuccessful(){
    /*TODO*/
}
void MainWindow::connectNotSuccessful(QString errorMessage){
     /*TODO*/
};
void MainWindow::networkErrorMessage(QString errorMessage){
     /*TODO*/
};
