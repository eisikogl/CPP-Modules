#include "HumanA.hpp"

HumanA::HumanA(std::string name,Weapon &newWeapon) : weapon_(newWeapon)
{
    _name = name;
}

void HumanA::attack()
{
    std::cout << _name << " attack with their " << weapon_.getType() << std::endl;
}