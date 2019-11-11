#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int windowWidth=800,windowHeight=400;

    QApplication a(argc, argv);
    MainWindow w(windowWidth,windowHeight);
    w.show();
    return a.exec();
}
