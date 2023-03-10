#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string name) 
	: ClapTrap(name,100,100,30),_name(name)
{
	std::cout << "FragTrap " << name << " created with health " << _HitPoints << ", energy " << _EnergyPoints << ", and attack damage " << _AttackDamage << ".\n";
}

FragTrap::FragTrap(const FragTrap &copy)
	:ClapTrap(copy)
{
	std::cout << "FragTrap " << _name << " copied with health " << _HitPoints << ", energy " << _EnergyPoints << ", and attack damage " << _AttackDamage << ".\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout <<"copy assigment operator called from FragTrap"<<std::endl;
	if(this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << _name << " has been destroyed by FragTrap Destructor" << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << _name << " I request the highest of Fives " << std::endl;
}