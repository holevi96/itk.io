#include "tester.h"
#include <QDebug>
#include <QTimer>
#include <string.h>
#include "gamecore.h"
#include "../../shared/shared/globalconstants.h"

using namespace std;

tester::tester(): gc(10000, 10000,  0.1, 1, 100)
{
    timeStep = 100;
    connect(this, SIGNAL(testSignal()), this, SLOT(test()));
    testSignal();
}

void tester::test(){
    steps[5]="init";
    steps[10]="toGame";
    steps[44]="report";
    steps[48]="ettol";
    steps[49]="eddig";

    for(unsigned i = 0; i<200; i++){
        steps[50+i]="report";
    }

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
            qDebug()<<gc.getX(shipNum)<<";"<<gc.getY(shipNum);
            qDebug()<<gc.isInGame(shipNum);
            shipNum=2;
            qDebug()<<"USS Enterprise";
            qDebug()<<gc.getX(shipNum)<<";"<<gc.getY(shipNum);
            qDebug()<<gc.isInGame(shipNum);
        }else if (order == "ettol"){
            qDebug()<<"TESTER: ettol";
            gc.speed(1,verticalDirection::FORWARD);

        }else if (order == "eddig"){
            gc.speed(1,verticalDirection::REST);
            qDebug()<<"TEATER: eddig";
        }else if (order == "toGame"){
            qDebug()<<"csatlakoznak elvileg";
            gc.joinToGame(1);
            gc.joinToGame(2);
        }
    }
}
