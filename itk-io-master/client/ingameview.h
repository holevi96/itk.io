#ifndef INGAMEVIEW_H
#define INGAMEVIEW_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class IngameView:public QWidget
{
public:
    IngameView(QMainWindow* w);
    ~IngameView();

private:
    QMainWindow* window;

    QGraphicsView* view;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;
};

#endif // INGAMEVIEW_H
