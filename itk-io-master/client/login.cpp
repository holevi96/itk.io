#include "login.h"

Login::Login(QMainWindow* w) : QWidget(w),window(w)
{
    joinButton=new QPushButton("Join",this);
    joinButton->setFixedSize(80,30);
    connect(joinButton,SIGNAL(clicked()),window,SLOT(startgame()));
}
