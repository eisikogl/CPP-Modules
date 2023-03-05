#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
private:
    std::string _name;
    Weapon *weapon_;
public:
    HumanB(std::string);
    void setWeapon(Weapon&);
    void attack();
};


#endif