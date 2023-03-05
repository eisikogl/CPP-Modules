#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon_ = &newWeapon;
}

void HumanB::attack()
{
    std::cout << _name << " attacks with their " << weapon_->getType() << std::endl;
}
