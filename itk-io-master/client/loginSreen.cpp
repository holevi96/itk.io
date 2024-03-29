#include "loginSreen.h"
#include <QDebug>

QString LoginScreen::getName()
{
    return nameBox->text();
}

QString LoginScreen::getIP()
{
    return ipBox->text();
}

int LoginScreen::getPort()
{
    return portBox->text().toInt();
}

LoginScreen::LoginScreen(MainWindow* w, QStackedWidget* st) : QWidget(st),window(w)
{
    nameBox=new QLineEdit(this);
    nameBox->setFixedSize(lineWidth,lineHeight);
    nameBox->move(window->width()/2-nameBox->width()/2,window->height()/2-nameBox->height()*4);
    nameBox->setPlaceholderText("Name");

    ipBox=new QLineEdit(this);
    ipBox->setFixedSize(lineWidth,lineHeight);
    ipBox->move(window->width()/2-ipBox->width()/2,window->height()/2-ipBox->height()*2);
    ipBox->setPlaceholderText("IP");
    ipBox->setText("127.0.0.1");

    portBox=new QLineEdit(this);
    portBox->setFixedSize(lineWidth,lineHeight);
    portBox->move(window->width()/2-portBox->width()/2,window->height()/2);
    portBox->setPlaceholderText("Port");
    portBox->setText("5002");

    joinButton=new QPushButton("Join server",this);
    joinButton->setFixedSize(80,30);
    joinButton->move(window->width()/2-joinButton->width()/2,window->height()/2+joinButton->height()*2);

    connect(joinButton,SIGNAL(clicked()),window,SLOT(connectToServer()));

}
