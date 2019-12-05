#include "player.h"



Player::Player(int id):id(id)
{
    this->d =new  Design();
}

Design* Player::getDesign() const
{
    return d;
}

void Player::setName(QString name)
{
    this->name = name;
}
