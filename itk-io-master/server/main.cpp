#include "mainwindow.h"
#include "server/core/tester.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //tester t; //Donát kis házi "core" tesztjét indítja be
    return a.exec();
}
