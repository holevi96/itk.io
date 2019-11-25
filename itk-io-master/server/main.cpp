#include "mainwindow.h"
#include "server/core/tester.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    tester t;
    return a.exec();
}
