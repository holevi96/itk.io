#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <QtCore>
#include "globalconstants.h"
#include "serializehelper.h"

#include <list>
using namespace std;


class Serializable
{
public:
     ~Serializable();
     virtual QString getSerializedClass() = 0;
     virtual void setClassBySerializedString(QString serial) = 0;
};

#endif // SERIALIZABLE_H
