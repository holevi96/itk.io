#include "design.h"

Design::Design()
{

}

Design::Design(QString serial)
{
    QStringList pieces = serial.split("|");
    this->color = pieces[1].toInt();
}
Design::~Design(){

}
QString Design::getSerializedClass(){
    QString sid = QString::number(color);
    QString message = sid;
    return message;

}

