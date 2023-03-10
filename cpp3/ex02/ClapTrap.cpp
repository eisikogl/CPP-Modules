#include "ClapTrap.hpp"

//default constructor
ClapTrap::ClapTrap()
    : _name("")
{
    std::cout << _name << ": Has been created with the default Constructor" << std::endl;
}

//constructor
ClapTrap::ClapTrap(std::string name,int hitpoints,int energy,int attack)
    : _name(name),_HitPoints(hitpoints),_EnergyPoints(energy), _AttackDamage(attack)
{
    std::cout << _name << ": Has been created with the Claptrap Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name)
{
    std::cout << _name << ": Has been created with the Claptrap Constructor" << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _HitPoints = copy._HitPoints;
    _EnergyPoints = copy._EnergyPoints;
    _AttackDamage = copy._AttackDamage;
}

//copy assignment
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    _HitPoints = copy._HitPoints;
    _EnergyPoints = copy._EnergyPoints;
    _AttackDamage = copy._AttackDamage;
    return *this;
}

//destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " Destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
     //target.hitpoints - attackdamage
    //energy - 1
    std::cout<< std::endl;
    if(_EnergyPoints > 0 && _HitPoints > 0)
    {
        std::cout << _name << " attacks " << target << " causing: " << _AttackDamage << " points of damage" << std::endl;
    }
    _EnergyPoints--;
    std::cout << _name << " Current Energy: " << _EnergyPoints << std::endl;
    std::cout<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    //hitpoint - amount
    //if hitpoint <= 0 dead
    std::cout<< std::endl;
    _HitPoints -= amount;
    if(_HitPoints > 0)
    {
        std::cout << _name << " took " << amount << " damage" << std::endl << "Current Hitpoints: " << _HitPoints << std::endl;
    }
    else
    {
        std::cout << _name << " has no more Hitpoints left therefore died in pain" << std::endl; 
    }
    std::cout<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    //hitpoints + amount
    //energy - 1
    std::cout<< std::endl;
    if(_EnergyPoints > 0)
    {
        std::cout << _name << " uses Repair and gains " << amount << " Hitpoints" << std::endl;
        _HitPoints += amount;
        std::cout << _name << " Current Hitpoints: " << _HitPoints << std::endl;
        _EnergyPoints--;
        std::cout << _name << " Current Energy: " << _EnergyPoints << std::endl;
    }
    else
    {
        std::cout << _name << " has no more Energy left" << std::endl;
    }
   std::cout<< std::endl;
}

std::string ClapTrap::getname()
{
    return _name;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
    _AttackDamage = amount;
    std::cout <<std::endl<< _name << " uses magic and has " << amount << " Attack damage now " << std::endl<<std::endl;
} 

unsigned int ClapTrap::getAttackDamage()
{
    return _AttackDamage;
}