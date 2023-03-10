#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name,100,50,20),_name(name)
{
     std::cout << "ScavTrap " << name << " created with health " << _HitPoints << ", energy " << _EnergyPoints << ", and attack damage " << _AttackDamage << ".\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy)
	:ClapTrap(copy)
{
	std::cout << "ScavTrap " << _name << " copied with health " << _HitPoints << ", energy " << _EnergyPoints << ", and attack damage " << _AttackDamage << ".\n";
}

ScavTrap::ScavTrap()
	:ClapTrap()
{
	std::cout << "ScavTrap created by default ScavTrap constructor" << std::endl; 
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout <<"copy assigment operator called from SCAVTRAP"<<std::endl;
	if(this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap "<< _name <<" destroyed."<<std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if(_EnergyPoints > 0)
	{
	std::cout << "ScavTrap " << _name << " attacks " << target << " with full force" << std::endl;
	_EnergyPoints--;
	std::cout << "ScavTrap " << _name << " current Energy: " << _EnergyPoints <<std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " has no more Energy " << std::endl;
	}

}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap named " << _name << " enters Gatekeeper mode"<<std::endl;
}