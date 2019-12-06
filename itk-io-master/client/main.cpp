#include "mainwindow.h"
#include <QApplication>

#include <QObject>
#include <QThread>
#include "completeplayerinfo.h"




int main(int argc, char *argv[])
{
    int windowWidth=700,windowHeight=700;

    QApplication a(argc, argv);
    MainWindow w(windowWidth,windowHeight);
    w.show();
    return a.exec();
}
