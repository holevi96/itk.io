#include "inGameMenu.h"

InGameMenu::InGameMenu(MainWindow *w, QStackedWidget* st) : QWidget(st),window(w)
{
    joinButton=new QPushButton("Join game",this);
    joinButton->setFixedSize(80,30);
    joinButton->move(window->width()/2-joinButton->width()/2,window->height()/2+joinButton->height()*2);

    connect(joinButton,SIGNAL(clicked()),window,SLOT(joinGame()));
}


