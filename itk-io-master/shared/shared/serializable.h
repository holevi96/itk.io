#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <QtCore>
#include "globalconstants.h"


#include <list>
using namespace std;


class Serializable
{
public:
     virtual QString getSerializedClass() = 0;
    Serializable();
    virtual ~Serializable();
    // virtual void setClassBySerializedString(QString serial) = 0;
};

#endif // SERIALIZABLE_H
