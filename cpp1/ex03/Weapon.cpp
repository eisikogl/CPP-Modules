#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

const std::string Weapon::getType()
{
    return _type;
}

void Weapon::setType(std::string type)
{
    _type = type;
}