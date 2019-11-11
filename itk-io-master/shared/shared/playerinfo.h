#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include <QtCore>
#include "serializable.h"


class Playerinfo : public Serializable{
public:
    Playerinfo();
protected:
    int id;
private:

};

#endif // PLAYERINFO_H
