#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int windowWidth=1000,windowHeight=800;

    QApplication a(argc, argv);
    MainWindow w(windowWidth,windowHeight);
    w.show();
    return a.exec();
}
