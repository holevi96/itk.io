#ifndef INGAMEVIEW_H
#define INGAMEVIEW_H

#include <QWidget>
#include <QStackedWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "mainwindow.h"

class MainWindow;

class IngameView:public QWidget
{
public:
    IngameView(MainWindow* w, QStackedWidget* st);
    ~IngameView();

private:
    MainWindow* window;

    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;
};

#endif // INGAMEVIEW_H
