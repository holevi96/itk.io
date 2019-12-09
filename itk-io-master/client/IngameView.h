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
#include <QListWidget>
#include <QGraphicsEllipseItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
//#include <chrono>

#include "mainwindow.h"
#include "completeplayerinfo.h"
#include "globalconstants.h"

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
        QGraphicsPixmapItem* body;
        //QGraphicsRectItem* body;
        QGraphicsPixmapItem* leftFire;
        QGraphicsPixmapItem* rightFire;
        QProgressBar* health;
        QLabel* name;
        QGraphicsEllipseItem* range;
        QGraphicsScene* scene;
        QGraphicsProxyWidget *healthProxy, *nameProxy;

        int id;

        int width,length;

        int nameVerticalOffset=-75;
        int healthVerticalOffset=-60;
    public:
        GraphicsShipItem(QGraphicsScene *scene, CompletePlayerInfo &player);
        void refreshData(CompletePlayerInfo &player);
        ~GraphicsShipItem();
        const QGraphicsPixmapItem* getBody(){return body;}
        //const QGraphicsRectItem* getBody(){return body;}

    };

    MainWindow* window;

    QGraphicsView* view;
    QGraphicsScene* scene;

    QProgressBar* leftCannon, *rightCannon;
    QListWidget* scores;

    QMap<int,GraphicsShipItem*> ships;

    static int ownPlayerRotation;

    int score=0;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public slots:

    void refreshPlayers();
    void refreshServerInfo();

signals:
    void setLastScore(int score);
    //void setScore(int score);
};

#endif // INGAMEVIEW_H
