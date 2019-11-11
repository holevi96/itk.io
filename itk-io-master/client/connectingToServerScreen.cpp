#include "connectingtoserverscreen.h"

ConnectingToServerScreen::ConnectingToServerScreen(QMainWindow* w) : QWidget(w),window(w)
{
    label=new QLabel("Loading...",this);
    label->setFixedSize(50,30);
    label->move(window->width()/2-label->width()/2,window->height()/2-label->height()/2);
}
