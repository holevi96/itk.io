#include "ingameScreen.h"

#include <QDebug>
#include <QString>



IngameView::IngameView(MainWindow* w, QStackedWidget* st) : QWidget(st),window(w)
{
    view=new QGraphicsView(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,window->width()-110,window->height()-110);
    view->setFixedSize(window->width()-100,window->height()-100);
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //qDebug()<<QString(window->width())+" "+QString(window->height());

    view->setScene(scene);

    rect=new QGraphicsRectItem(300,300,100,100);

    scene->addItem(rect);
}

IngameView::~IngameView()
{
    delete rect;
}
