#include "playerinfo.h"

Playerinfo::Playerinfo()
{

}

Playerinfo::Playerinfo(int id):id(id)
{

}

Playerinfo::~Playerinfo()
{

}

int Playerinfo::getId() const
{
    return id;
}
