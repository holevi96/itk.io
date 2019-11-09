#include "mainwindow.h"
#include "clientgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int windowWidth=1000,windowHeight=800;

    QApplication a(argc, argv);
    MainWindow w(windowWidth,windowHeight);
    ClientGame game(&w);
    w.show();
    return a.exec();
}
