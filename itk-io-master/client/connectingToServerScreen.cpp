#include "connectingToServerScreen.h"

ConnectingToServerScreen::ConnectingToServerScreen(MainWindow* w,QStackedWidget* st) : QWidget(st),window(w)
{
    label=new QLabel("Loading...",this);
    label->setFixedSize(100,50);
    label->move(window->width()/2-label->width()/2,window->height()/2-label->height()/2);
}
