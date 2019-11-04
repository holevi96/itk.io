#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include "serializable.h"

class Playerinfo : public Serializable
{
public:
    Playerinfo();
protected:
    int id;

};

#endif // PLAYERINFO_H
