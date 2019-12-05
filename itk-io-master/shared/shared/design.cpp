#include "design.h"
int Design::d = 1;
Design::Design()
{
    this->color = Design::d;
    Design::d++;
}

Design::Design(QString serial)
{
    QStringList pieces = serial.split("|");
    this->color = pieces[1].toInt();
}

Design::Design(int color)
{
    this->color = color;
}
Design::~Design(){

}
QString Design::getSerializedClass(){
    QString sid = QString::number(color);
    QString message = sid;
    return message;

}

QString Design::getName()
{

}

