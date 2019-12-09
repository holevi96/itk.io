#include "inGameMenu.h"

InGameMenu::InGameMenu(MainWindow *w, QStackedWidget* st) : QWidget(st),window(w)
{
    joinButton=new QPushButton("Join game",this);
    joinButton->setFixedSize(80,30);
    joinButton->move(window->width()/2-joinButton->width()/2,window->height()/2+joinButton->height()*2);

    lastScoreLabel=new QLabel(this);
    highScoreLabel=new QLabel(this);

    lastScoreLabel->setText("Last Score: 0");
    highScoreLabel->setText("High Score: 0");

    lastScoreLabel->setGeometry(window->width()/2-50,200,300,100);
    highScoreLabel->setGeometry(window->width()/2-50,300,300,100);

    connect(joinButton,SIGNAL(clicked()),window,SLOT(joinGame()));
}

void InGameMenu::setLastScore(int score)
{
    if(score!=-1){
        lastScore=score;
    }
    if(lastScore>highScore){
        highScore=lastScore;
    }

    lastScoreLabel->setText("Last Score: "+QString::number(lastScore));
    highScoreLabel->setText("High Score: "+QString::number(highScore));
    ////qDebug()<<"/t/t lastscore:"<<score;
}


