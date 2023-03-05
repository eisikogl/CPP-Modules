#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
    std::string _name;
    Weapon &weapon_;
public:
    HumanA(std::string, Weapon&);
    void attack();
};

#endif