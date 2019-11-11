#include "design.h"

Design::Design()
{

}
QString Design::getSerializedClass(){
    QString sid = QString::number(color);
    QString message = sid;
    return message;

}

void Design::setClassBySerializedString(QString serial){
    QStringList pieces = serial.split("|");
    this->color = pieces[1].toInt();
}
