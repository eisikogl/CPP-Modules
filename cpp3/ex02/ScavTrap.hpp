#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	std::string _name;
	int _HitPoints = 100;
	int _EnergyPoints = 50;
	int _AttackDamage = 20;
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);

	void attack(const std::string &target);
    void guardGate();
};



#endif