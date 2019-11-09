#ifndef CLIENTGAME_H
#define CLIENTGAME_H

#include "mainwindow.h"

//static MainWindow window;

class ClientGame
{
public:
    ClientGame(MainWindow* w);

private:
    MainWindow* mainwindow;
};

#endif // CLIENTGAME_H
