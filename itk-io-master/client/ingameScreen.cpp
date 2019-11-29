#include "ingameScreen.h"

#include <QDebug>
#include <QString>



IngameView::IngameView(MainWindow* w, QStackedWidget* st) : QWidget(st),window(w),ships()
{
    view=new QGraphicsView(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,window->width()-110,window->height()-110);
    view->setFixedSize(window->width()-100,window->height()-100);
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //qDebug()<<QString(window->width())+" "+QString(window->height());

    setFocus();

    view->setScene(scene);

    connect(window,SIGNAL(refreshPlayers()),this,SLOT(refreshPlayers()));

    /*rect=new QGraphicsRectItem(300,300,100,100);

    scene->addItem(rect);*/
}

IngameView::~IngameView()
{
    //delete rect;
}

void IngameView::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()){
        return;
    }

    //qDebug()<<event->key();
    switch(event->key()){
    case Qt::Key_Escape:
        window->leaveGame();
        break;

    //arrow keys
    case Qt::Key_Left:
        window->getClient()->pressedTurnLeftButton();
        break;
    case Qt::Key_Right:
        window->getClient()->pressedTurnRightButton();
        break;
    case Qt::Key_Up:
        window->getClient()->pressedForwardButton();
        break;
    case Qt::Key_Down:
        window->getClient()->pressedBackwardButton();
        break;
    case Qt::Key_Control:
        window->getClient()->pressedFireLeftButton();
        break;
    case Qt::Key_0:
        window->getClient()->pressedFireRightButton();
        break;

    //WASD
    case Qt::Key_A:
        window->getClient()->pressedTurnLeftButton();
        break;
    case Qt::Key_D:
        window->getClient()->pressedTurnRightButton();
        break;
    case Qt::Key_W:
        window->getClient()->pressedForwardButton();
        break;
    case Qt::Key_S:
        window->getClient()->pressedBackwardButton();
        break;
    case Qt::Key_Q:
        window->getClient()->pressedFireLeftButton();
        break;
    case Qt::Key_E:
        window->getClient()->pressedFireRightButton();
        break;


    default:
        break;
    }

}

void IngameView::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()){
        return;
    }

    //qDebug()<<"key released";
    switch(event->key()){

    //arrow keys
    case Qt::Key_Left:
        window->getClient()->releasedTurnLeftButton();
        break;
    case Qt::Key_Right:
        window->getClient()->releasedTurnRightButton();
        break;
    case Qt::Key_Up:
        window->getClient()->releasedForwardButton();
        break;
    case Qt::Key_Down:
        window->getClient()->releasedBackwardButton();
        break;
    case Qt::Key_Control:
        window->getClient()->releasedFireLeftButton();
        break;
    case Qt::Key_0:
        window->getClient()->releasedFireRightButton();
        break;

    //WASD
    case Qt::Key_A:
        window->getClient()->releasedTurnLeftButton();
        break;
    case Qt::Key_D:
        window->getClient()->releasedTurnRightButton();
        break;
    case Qt::Key_W:
        window->getClient()->releasedForwardButton();
        break;
    case Qt::Key_S:
        window->getClient()->releasedBackwardButton();
        break;
    case Qt::Key_Q:
        window->getClient()->releasedFireLeftButton();
        break;
    case Qt::Key_E:
        window->getClient()->releasedFireRightButton();
        break;


    default:
        break;
    }
}

void IngameView::refreshPlayers()
{

    for (list<CompletePlayerInfo>::iterator iter=window->getGameData().completePlayerInfo->begin();iter!=window->getGameData().completePlayerInfo->end();iter++) {
        QMap<int,QGraphicsRectItem*>::iterator it=ships.find((*iter).id);
        if(it!=ships.end()){        //új elem

        }else{                      //frissített elem

        }
    }
}
