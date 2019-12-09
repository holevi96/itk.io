#include "IngameView.h"

#include <QDebug>
#include <QString>

int IngameView::ownPlayerRotation = 0;

IngameView::IngameView(MainWindow* w, QStackedWidget* st) : QWidget(st),window(w),ships()
{
    view=new QGraphicsView(this);
    scene=new QGraphicsScene(this);


    QPixmap pim(QPixmap(":/images/background.jpg"));
    //setStyleSheet("background-image: url(::/images/background.jpg)");
    scene->setSceneRect(0,0,window->width()-110,window->height()-110);

    const QPen *qp = new QPen(Qt::red, 20, Qt::SolidLine,Qt::SquareCap, Qt::RoundJoin);

     scene->addLine(0,0,0,10000,*qp);
     scene->addLine(0,0,10000,0,*qp);
     scene->addLine(10000,0,0,10000,*qp);
     scene->addLine(0,10000,10000,0,*qp);


    view->setFixedSize(window->width()-120,window->height()-50);
    scene->setBackgroundBrush(pim.scaled(window->width()-110,window->height()-110,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scores=new QListWidget(this);
    scores->setGeometry(window->width()-120,0,120,window->height()-50);

    leftCannon=new QProgressBar(this);
    rightCannon=new QProgressBar(this);

    leftCannon->setGeometry(0,window->height()-50,window->width()/2-20,50);
    leftCannon->setTextVisible(false);
    rightCannon->setGeometry(window->width()-window->width()/2+20,window->height()-50,window->width()/2-20,50);
    rightCannon->setTextVisible(false);

    leftCannon->setRange(0,100);
    leftCannon->setValue(100);
    rightCannon->setRange(0,100);
    rightCannon->setValue(100);

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
    long lastSinked=0;

    QStringList stringList;


    //elemek frissítése/hozzáadása
    for (list<CompletePlayerInfo*>::iterator iter=window->getGameData().completePlayerInfo.begin();iter!=window->getGameData().completePlayerInfo.end();iter++) {
        //qDebug()<<"asdasdasdasd";
        //qDebug()<<(*iter)->name;
        stringList.push_back(QString::number((*iter)->score)+":  "+(**iter).name);


        QMap<int,GraphicsShipItem*>::iterator it=ships.find((*iter)->id);
        if(it==ships.end()){        //új elem
            qDebug()<<"új hajó: "<<(*iter)->name;
            ships.insert((*iter)->id,new GraphicsShipItem(scene,**iter));
        }else{                      //frissített elem
            qDebug()<<"frissített hajó: "<<(*iter)->name;
            (*it)->refreshData(**iter);

        }


        //saját játékos
        if((**iter).id==window->getGameData().playerId){
            if ((**iter).lastFireLeft>(**iter).rechargeTime) {
                (**iter).lastFireLeft=(**iter).rechargeTime;
            }
            if ((**iter).lastFireRight>(**iter).rechargeTime) {
                (**iter).lastFireRight=(**iter).rechargeTime;
            }
            leftCannon->setRange(0,(**iter).rechargeTime);
            leftCannon->setValue((**iter).lastFireLeft);
            qDebug()<<(**iter).rechargeTime<<"/"<<(**iter).lastFireLeft;
            rightCannon->setRange(0,(**iter).rechargeTime);
            rightCannon->setValue((**iter).lastFireRight);

            //qDebug()<<(**iter).rechargeTime<<"/"<<(**iter).rechargeStatus;

            score=(**iter).score;
            lastSinked=(**iter).lastSink;
            setLastScore(score);
        }
    }
    scores->clear();
    scores->addItems(stringList);
    scores->sortItems();



    QList<int> delList;

    //kilépett játékosok hajóinak törlése
    for (QMap<int,GraphicsShipItem*>::iterator it=ships.begin();it!=ships.end();it++) {

        bool del=true;
        for (list<CompletePlayerInfo*>::iterator iter=window->getGameData().completePlayerInfo.begin();iter!=window->getGameData().completePlayerInfo.end();iter++) {
            if(it.key()==(*iter)->id && (*iter)->score>-1){
                del=false;
                //qDebug()<<"del2";
                //delList.push_back(it.key());
                break;
            }

        }
        if(del){
            qDebug()<<"toroltem egy hajot";
            //ships.remove(it.key());
            delList.push_back(it.key());
        }
    }

    for (QList<int>::iterator it=delList.begin();it!=delList.end();it++) {
        delete ships.find(*it).value();
        ships.remove(*it);

    }

qDebug()<<ships.size();
if(ships.find(window->getGameData().playerId)!=ships.end()){
    view->resetTransform();
    view->centerOn((ships.find(window->getGameData().playerId)).value()->getBody());
    IngameView::ownPlayerRotation = (ships.find(window->getGameData().playerId)).value()->getBody()->rotation();
    view->rotate(-(ships.find(window->getGameData().playerId)).value()->getBody()->rotation());
}

    if (score==-1 && lastSinked<2000) {
        window->leaveGame();
    }

    qDebug()<<"ships.size(): "<<ships.size();
}

void IngameView::refreshServerInfo()
{
    scene->setSceneRect(0,0,window->getGameData().serverInfo.sizeX,window->getGameData().serverInfo.sizeY);
    //qDebug()<<"IngameView::refreshServerInfo";
    //qDebug()<<window->getGameData().serverInfo.sizeX;
    //qDebug()<<window->getGameData().serverInfo.sizeY;
}


/*
 * GraphicsShipItem konstruktor
 *
 * */
IngameView::GraphicsShipItem::GraphicsShipItem(QGraphicsScene *s, CompletePlayerInfo &player):scene(s){

    qDebug()<<"GraphicsShipItem created";

    body=new QGraphicsPixmapItem();
    //body=new QGraphicsRectItem();
    health=new QProgressBar();
    name=new QLabel(player.name);
    //range=new QGraphicsEllipseItem(qreal(player.x),qreal(player.y),qreal(defaultRange*2),qreal(defaultRange*2));
    range=new QGraphicsEllipseItem(0,0,qreal(defaultRange*2),qreal(defaultRange*2));

    //leftFlame

    //QPixmap pim("ship.png");

    //body->setBrush(pim);
    leftFire = new QGraphicsPixmapItem(QPixmap(":/images/fire2.png").scaled(10,10));
    rightFire = new QGraphicsPixmapItem(QPixmap(":/images/fire1.png").scaled(10,10));

    leftFire->setParentItem(body);
    rightFire->setParentItem(body);
    //scene->setBackgroundBrush(pim.scaled(scene->width(),scene->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    scene->addItem(body);
    scene->addItem(leftFire);
    scene->addItem(rightFire);
    healthProxy = scene->addWidget(health);
    nameProxy = scene->addWidget(name);
    scene->addItem(range);

     //QImage image(":/images/fire.png");

      /*QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
      item->setPos(qreal(player.x),qreal(player.y));
      scene->addItem(item);
      item->setParentItem(body);*/



    //body->setRect(player.x-player.size/8,player.y-player.size/2,player.size/4,player.size);
    //body->setTransformOriginPoint(body->x()+body->rect().width()/2,body->y()+body->rect().height()/2);
    //body->setRotation(player.phi);

    //health->setRange(0,player.maxLife);
    //health->setValue(player.life);
    health->setGeometry(player.x-25,player.y+healthVerticalOffset,50,15);
    //health->setGeometry(0,0,10,10);
    health->setTextVisible(false);

    name->setGeometry(player.x-25,player.y+nameVerticalOffset,50,15);
    //name->setGeometry(0,0,10,10);

    range->setOpacity(0.1);

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

    qDebug()<<"refreshData: "<<player.name;
    //qDebug()<<"r1";
//qDebug()<<body->x();
//qDebug()<<player.name;
    //body->setRect(player.x-width/2,player.y-length/2,width,length);

    //this->setStyleSheet("background-image: url(:/bg.jpg)");
    QPixmap pixmap=QPixmap(":/images/ship.png").scaled(width,length);
    //pixmap.fill(QColor(0,0,0,0));
    body->setPixmap(pixmap);
    body->setPos(player.x-width/2,player.y-length/2);
    //body->setTransformOriginPoint(player.x,player.y);
    body->setTransformOriginPoint(width/2,length/2);
    body->setRotation(-player.phi-90);
    //body->show();


    leftFire->setPos(width/2+5,length/2-5);
    leftFire->setTransformOriginPoint(0,0);
    //leftFire->setRotation(-player.phi-90);
    leftFire->setVisible(player.getLastFireRight()<100);


    rightFire->setPos(width/2-15,length/2-5);
    rightFire->setTransformOriginPoint(0,0);
    //rightFire->setRotation(-player.phi-90);
    rightFire->setVisible(player.getLastFireLeft()<100);


//scene->removeItem(body);
//delete body;
//body=new QGraphicsRectItem(player.x-width/2,player.y-length/2,width,length);
//body->setTransformOriginPoint(player.x,player.y);
//body->setRotation(player.phi);
//scene->addItem(body);

    //body->setRotation(90);
    //body->setRotation(180);
    //body->setRotation(-90);

    nameProxy->setTransformOriginPoint(25,-nameVerticalOffset);
    nameProxy->setRotation(ownPlayerRotation);
    name->move(player.x-25,player.y+nameVerticalOffset);

    healthProxy->setTransformOriginPoint(25,-healthVerticalOffset);
    healthProxy->setRotation(ownPlayerRotation);
    health->move(player.x-25,player.y+healthVerticalOffset);
    health->setRange(0,player.maxLife);
    health->setValue(player.life);
    //qDebug()<<health->maximum()<<"/"<<health->value();

    range->setPos(qreal(player.x-defaultRange),qreal(player.y-defaultRange));
    //range->setPos(0,0);

    scene->views().at(0)->show();

    //qDebug()<<"";
    //qDebug()<<player.size;
    //qDebug()<<body->x();
    //qDebug()<<player.x-player.size/8;
}

IngameView::GraphicsShipItem::~GraphicsShipItem(){
    qDebug()<<"GraphicsShipItem destroyed";

    delete body;
    delete health;
    delete name;
    delete range;
}
