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
    void test01();
    void test02();
    void test03();
    void test04();
    void test05();
    void test06();
    void test07();
    void test08();
    void test09();
    void test10();
};

#endif // TESTER_H
