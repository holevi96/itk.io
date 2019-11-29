#ifndef INGAMEVIEW_H
#define INGAMEVIEW_H

#include <QWidget>
#include <QStackedWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>

#include "mainwindow.h"

class MainWindow;

class IngameView:public QWidget
{
public:
    IngameView(MainWindow* w, QStackedWidget* st);
    ~IngameView() override;

private:

    MainWindow* window;

    QGraphicsView* view;
    QGraphicsScene* scene;

    QMap<int,QGraphicsRectItem*> ships;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:

    void refreshPlayers();
};

#endif // INGAMEVIEW_H
