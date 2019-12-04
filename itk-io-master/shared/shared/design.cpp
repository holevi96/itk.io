#include "design.h"

Design::Design()
{
    this->color = rand() % 10;
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

