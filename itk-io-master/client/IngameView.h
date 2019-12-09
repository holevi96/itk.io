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
        QGraphicsRectItem* body;
        QProgressBar* health;
        QLabel* name;
        QGraphicsEllipseItem* range;
        QGraphicsScene* scene;

        int id;

        int width,length;

        int nameVerticalOffset=-45;
        int healthVerticalOffset=-30;
    public:
        GraphicsShipItem(QGraphicsScene *scene, CompletePlayerInfo &player);
        void refreshData(CompletePlayerInfo &player);
        ~GraphicsShipItem();
        const QGraphicsRectItem* getBody(){return body;}

    };

    MainWindow* window;

    QGraphicsView* view;
    QGraphicsScene* scene;

    QProgressBar* leftCannon, *rightCannon;
    QListWidget* scores;

    QMap<int,GraphicsShipItem*> ships;

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
