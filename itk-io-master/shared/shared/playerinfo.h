#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include <QtCore>
#include "serializable.h"


class Playerinfo : public Serializable{
public:
    QString getSerializedClass() = 0;
    void setClassBySerializedString(QString serial) = 0;
protected:
    int id;
private:

};

#endif // PLAYERINFO_H
