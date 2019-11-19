#ifndef TESTER_H
#define TESTER_H

#include <QObject>
#include <QWidget>

class tester : public QObject
{
    Q_OBJECT
signals:
    void testSignal();
private slots:
    void test();
public:
    tester();
};

#endif // TESTER_H
