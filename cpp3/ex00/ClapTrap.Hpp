#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


class ClapTrap
{
    private:
        std::string _name;
        int _HitPoints;
        int _EnergyPoints;
        int _AttackDamage;
    public:
        ClapTrap(std::string);
        ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator = (const ClapTrap &copy);
        ~ClapTrap();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getname();
        void setAttackDamage(unsigned int amount);
        unsigned int getAttackDamage();
};

#endif