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
    qDebug()<<"refreshPlayers";

    //elemek frissítése/hozzáadása
    for (list<CompletePlayerInfo>::iterator iter=window->getGameData().completePlayerInfo->begin();iter!=window->getGameData().completePlayerInfo->end();iter++) {
        QMap<int,GraphicsShipItem*>::iterator it=ships.find((*iter).id);
        if(it!=ships.end()){        //új elem
            ships.insert((*iter).id,new GraphicsShipItem(scene,*iter));
        }else{                      //frissített elem
            (*it)->refreshData(*iter);
        }
    }

    //kilépett játékosok hajóinak törlése
    for (QMap<int,GraphicsShipItem*>::iterator it=ships.begin();it!=ships.end();it++) {
        bool del=true;
        for (list<CompletePlayerInfo>::iterator iter=window->getGameData().completePlayerInfo->begin();iter!=window->getGameData().completePlayerInfo->end();iter++) {
            if(it.key()==(*iter).id){
                del=false;
                break;
            }
            if(del){
                ships.remove(it.key());
            }
        }
    }
}

IngameView::GraphicsShipItem::GraphicsShipItem(QGraphicsScene *scene, CompletePlayerInfo &player){

    qDebug()<<"GraphicsShipItem created";

    body=new QGraphicsRectItem();
    health=new QProgressBar();
    name=new QLabel(player.name);

    scene->addItem(body);
    scene->addWidget(health);
    scene->addWidget(name);

    body->setRect(player.x-player.size/8,player.y-player.size/2,player.size/4,player.size);
    body->setTransformOriginPoint(body->rect().width()/2,body->rect().height()/2);
    body->setRotation(90+player.phi);

    health->setRange(0,player.maxLife);
    health->setValue(player.life);
    health->setGeometry(int(body->rect().x()),int(body->rect().y())+healthVerticalOffset,50,30);

    name->setGeometry(int(body->rect().x()),int(body->rect().y())+nameVerticalOffset,50,30);

    id=player.id;
}

void IngameView::GraphicsShipItem::refreshData(CompletePlayerInfo &player)
{
    qDebug()<<"refreshData";

    body->setRect(player.x-player.size/8,player.y-player.size/2,player.size/4,player.size);
    health->move(player.x,player.y+healthVerticalOffset);
    name->move(player.x,player.y+nameVerticalOffset);

    body->setRotation(90+player.phi);

    health->setRange(0,player.maxLife);
    health->setValue(player.life);


}

IngameView::GraphicsShipItem::~GraphicsShipItem(){
    qDebug()<<"GraphicsShipItem destroyed";

    delete body;
    delete health;
    delete name;
}
