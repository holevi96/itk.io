#ifndef TESTER_H
#define TESTER_H

#include <QObject>
#include <QWidget>
#include <map>
#include "gamecore.h"

class tester : public QObject
{
    Q_OBJECT
signals:
    void testSignal();
private slots:
    void test();
    void testStep();
public:
    tester();
private:
    std::map<int,std::string> steps;
    int msNum=0;
    int timeStep;
    GameCore gc;
};

#endif // TESTER_H
