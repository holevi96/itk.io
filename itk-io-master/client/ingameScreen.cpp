#include "ingameScreen.h"

#include <QDebug>
#include <QString>



IngameView::IngameView(MainWindow* w, QStackedWidget* st) : QWidget(st),window(w),ships()
{
    view=new QGraphicsView(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,window->width()-110,window->height()-110);
    view->setFixedSize(window->width()-100,window->height()-100);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    //qDebug()<<QString(window->width())+" "+QString(window->height());

    setFocus();

    view->setScene(scene);

    connect(window,SIGNAL(refreshPlayers()),this,SLOT(refreshPlayers()));
    connect(window,SIGNAL(refreshServerInfo()),this,SLOT(refreshServerInfo()));

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
    qDebug()<<"IngameView::refreshPlayers";

    //elemek frissítése/hozzáadása
    for (list<CompletePlayerInfo*>::iterator iter=window->getGameData().completePlayerInfo.begin();iter!=window->getGameData().completePlayerInfo.end();iter++) {
        qDebug()<<"asdasdasdasd";
        qDebug()<<(*iter)->name;
        QMap<int,GraphicsShipItem*>::iterator it=ships.find((*iter)->id);
        if(it==ships.end()){        //új elem
            qDebug()<<"új hajó";
            ships.insert((*iter)->id,new GraphicsShipItem(scene,**iter));
        }else{                      //frissített elem
            qDebug()<<"frissített hajó";
            (*it)->refreshData(**iter);

        }
    }

    //kilépett játékosok hajóinak törlése
    for (QMap<int,GraphicsShipItem*>::iterator it=ships.begin();it!=ships.end();it++) {
        bool del=true;
        for (list<CompletePlayerInfo*>::iterator iter=window->getGameData().completePlayerInfo.begin();iter!=window->getGameData().completePlayerInfo.end();iter++) {
            if(it.key()==(*iter)->id){
                del=false;
                break;
            }
            if(del){
                ships.remove(it.key());
            }
        }
    }

    scene->views().at(0)->centerOn((ships.find(window->getGameData().playerId)).value()->getBody());
}

void IngameView::refreshServerInfo()
{
    scene->setSceneRect(0,0,window->getGameData().serverInfo.sizeX,window->getGameData().serverInfo.sizeY);
    qDebug()<<"IngameView::refreshServerInfo";
    qDebug()<<window->getGameData().serverInfo.sizeX;
    qDebug()<<window->getGameData().serverInfo.sizeY;
}


/*
 * GraphicsShipItem konstruktor
 *
 * */
IngameView::GraphicsShipItem::GraphicsShipItem(QGraphicsScene *s, CompletePlayerInfo &player):scene(s){

    qDebug()<<"GraphicsShipItem created";

    body=new QGraphicsRectItem();
    health=new QProgressBar();
    name=new QLabel(player.name);

    scene->addItem(body);
    scene->addWidget(health);
    scene->addWidget(name);



    //body->setRect(player.x-player.size/8,player.y-player.size/2,player.size/4,player.size);
    //body->setTransformOriginPoint(body->x()+body->rect().width()/2,body->y()+body->rect().height()/2);
    //body->setRotation(player.phi);

    //health->setRange(0,player.maxLife);
    //health->setValue(player.life);
    health->setGeometry(player.x,player.y+healthVerticalOffset,50,15);
    //health->setGeometry(0,0,10,10);
    health->setTextVisible(false);

    name->setGeometry(player.x,player.y+nameVerticalOffset,50,15);
    //name->setGeometry(0,0,10,10);

    id=player.id;

    //scene->views().at(0)->show();
    refreshData(player);
}
/*
 * GraphicsShipItem elemek frissítése
 * */
void IngameView::GraphicsShipItem::refreshData(CompletePlayerInfo &player)
{
    width=player.size/4;
    length=player.size;

    qDebug()<<"refreshData";
    //qDebug()<<"r1";
//qDebug()<<body->x();
qDebug()<<player.name;
    //body->setRect(player.x-player.size/8,player.y-player.size/2,player.size/4,player.size);
    //body->setTransformOriginPoint(player.x+body->rect().width()/2,player.y+body->rect().height()/2);
    //body->setRotation(player.phi);

    body->setRect(player.x-width/2,player.y-length/2,width,length);
    body->setTransformOriginPoint(player.x,player.y);
    body->setRotation(player.phi);


    //body->setRotation(90);
    //body->setRotation(180);
    //body->setRotation(-90);

    name->move(player.x,player.y+nameVerticalOffset);

    health->move(player.x,player.y+healthVerticalOffset);
    health->setRange(0,player.maxLife);
    health->setValue(player.life);

    scene->views().at(0)->show();

    //qDebug()<<"";
    //qDebug()<<player.size;
    qDebug()<<body->x();
    qDebug()<<player.x-player.size/8;
}

IngameView::GraphicsShipItem::~GraphicsShipItem(){
    qDebug()<<"GraphicsShipItem destroyed";

    delete body;
    delete health;
    delete name;
}
