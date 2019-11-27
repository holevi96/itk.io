#include "tester.h"
#include <QDebug>
#include <QTimer>
#include <string.h>
#include "gamecore.h"
#include "../../shared/shared/globalconstants.h"
#include <sstream>

using namespace std;

tester::tester(): gc(10000, 10000,  0.1, 1, 100)
{
    timeStep = 100;
    connect(this, SIGNAL(testSignal()), this, SLOT(test()));
    testSignal();
}

void segedDrawAShip(){
    ShipGraphicItem *s1 = new ShipGraphicItem(10);
    ShipGraphicItem *s2 = new ShipGraphicItem(0.01);
    //s1->setPos(100,0);
    //s2->setPos(100,0);
    //s2->setRotation(90);

    s1->setPos(10,-10);
    s1->setRotation(199);
    int N = 40;
    vector<vector<int>> v = vector<vector<int>>(N,vector<int>(N,0));
    for(int x=-N/2; x<N/2; x++){
        for(int y=-N/2; y<N/2; y++){
            s2->setPos(x,y);
            if(s1->collidesWithItem(s2))v[x+N/2][y+N/2]=1;
        }
    }
    for(int x=0; x<N; x++){
        stringstream ss;
        for(int y=0; y<N; y++){
            ss<<v[x][y]<<'_';
        }
        string str;
        ss>>str;
        qDebug()<<str.c_str();
    }
}

void tester::test01(){
    steps[5]="init";
    steps[10]="toGame";
    steps[44]="report";
    steps[48]="ettol";
    steps[49]="eddig";
    for(unsigned i = 0; i<200; i++){
        steps[50+i]="report";
    }
}

void tester::test02(){
    steps[5]="init";
    steps[6]="toGame";
    steps[14]="report";
    steps[20]="shoot";
    //for(unsigned i = 0; i<10; i++){
    //    steps[21+i]="report";
    //}
    steps[30]="shoot";
    steps[50]="shoot";
}

void tester::test(){
    //segedDrawAShip();
    //test01();
    test02();

    qDebug() << "TESTER: test just started";
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(testStep()));
    timer->start(timeStep);
}

void tester::testStep(){
    //msNum+=timeStep;
    msNum ++;
    map<int,string>::iterator it = steps.find(msNum);
    if(it!=steps.end()){
        string order = it->second;
        if(order == "init"){
            qDebug()<<"TESTER: init";
            gc.playerJoined(1,"Rogue One");
            gc.playerJoined(2,"USS Enterprise");
        }else if (order == "report") {
            int shipNum=1;
            qDebug()<<"TESTER: report"<<endl<<"Rogue One";
            qDebug()<<gc.getX(shipNum)<<";"<<gc.getY(shipNum)<<";"<<gc.getPhi(shipNum);
            qDebug()<<gc.isInGame(shipNum);
            shipNum=2;
            qDebug()<<"USS Enterprise";
            qDebug()<<gc.getX(shipNum)<<";"<<gc.getY(shipNum)<<";"<<gc.getPhi(shipNum);
            qDebug()<<gc.isInGame(shipNum);
        }else if (order == "ettol"){
            qDebug()<<"TESTER: ettol";
            gc.speed(1,verticalDirection::BACKWARD);
            gc.turn(2,turnDirection::LEFT);
        }else if (order == "eddig"){
            gc.speed(1,verticalDirection::REST);
            gc.turn(2,turnDirection::REST);
            qDebug()<<"TEATER: eddig";
        }else if (order == "toGame"){
            qDebug()<<"csatlakoznak elvileg";
            gc.joinToGame(1);
            gc.joinToGame(2);
        }else if (order == "shoot"){
            qDebug()<<"shot";
            gc.shoot(1,fireDirection::LEFTRIGHT);
        }
    }
}
