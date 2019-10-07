#include "mainwindow.h"
#include "mybutton.h"
#include "server/core/gamecore.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameCore gameCore(nullptr);

    MainWindow w;
    w.show();
    return a.exec();
}
