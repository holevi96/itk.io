#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"

#include <QtGui>
#include<QDebug>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsView *view = new QGraphicsView(this);
    int width = 1024;
    int height = 768;

    view->setFixedSize(width, height);
    view->setSceneRect(0, 0, width, height);

    QGraphicsScene *scene = new QGraphicsScene(view);
    scene->setSceneRect(0,0,1024,768);
    scene->setBackgroundBrush(Qt::blue);
    view->setScene(scene);

    rect = new QGraphicsEllipseItem(0,0,100,100);
    rect->setPos(200,100);
    qInfo() << rect->pos().rx();
    scene->addItem(rect);
    view->show();

    myButton *mb = new myButton(this);

    setFixedSize(1024, 768);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked(){
   qInfo() << "C++ Style Info Message";
   rect->setPos(rect->pos().rx(),rect->pos().ry()+10);
}

