#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    ~DiamondTrap();
	DiamondTrap(std::string);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const FragTrap &copy);

	void whoAmI();
};



#endif