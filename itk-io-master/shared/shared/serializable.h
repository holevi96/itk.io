#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <QtCore>

class Serializable
{
public:
    virtual QString getSerializedClass() = 0;
    virtual void setClassBySerializedString(QString serial) = 0;
};

#endif // SERIALIZABLE_H
