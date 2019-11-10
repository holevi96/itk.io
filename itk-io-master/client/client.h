#ifndef CLIENT_H
#define CLIENT_H

#include "mainwindow.h"

/*
 *    TODO
*/

class MainWindow;

class Client
{
public:
    MainWindow *window;


    Client(MainWindow *w);
    void clickedJoinServerButton(QString name, QString ipAddress, int portNum);

};

#endif // CLIENT_H
