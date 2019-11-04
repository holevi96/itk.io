#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <QtCore>
#include "globalconstants.h"


class Serializable
{
public:
    virtual QString getSerializedClass() = 0;
    virtual void setClassBySerializedString(QString serial) = 0;
    QString messageType;
    QString verticalDirectionToString(verticalDirection e);
    QString turnDirectionToString(turnDirection e);
    QString fireDirectionToString(fireDirection e);
    verticalDirection verticalDirectionFromString(QString str);
    turnDirection turnDirectionFromString(QString str);
    fireDirection fireDirectionFromString(QString str);
};

#endif // SERIALIZABLE_H
