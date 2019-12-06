#ifndef INGAMEVIEW_H
#define INGAMEVIEW_H

#include <QWidget>
#include <QStackedWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QProgressBar>
#include <QKeyEvent>

#include "mainwindow.h"
#include "completeplayerinfo.h"

class MainWindow;

class IngameView:public QWidget
{
    Q_OBJECT
public:
    IngameView(MainWindow* w, QStackedWidget* st);
    virtual ~IngameView() override;

private:
    class GraphicsShipItem{
    private:
        QGraphicsRectItem* body;
        QProgressBar* health;
        QLabel* name;

        int id;


        int nameVerticalOffset=-60;
        int healthVerticalOffset=-30;
    public:
        GraphicsShipItem(QGraphicsScene *scene, CompletePlayerInfo &player);
        void refreshData(CompletePlayerInfo &player);
        ~GraphicsShipItem();

    };

    MainWindow* window;

    QGraphicsView* view;
    QGraphicsScene* scene;

    QMap<int,GraphicsShipItem*> ships;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:

    void refreshPlayers();
};

#endif // INGAMEVIEW_H
