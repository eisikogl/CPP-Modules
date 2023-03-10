#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    std::string _name;
	int _HitPoints = 100;
	int _EnergyPoints = 100;
	int _AttackDamage = 30;
public:
    FragTrap();
    ~FragTrap();
    FragTrap(std::string);
    FragTrap(const FragTrap &copy);
    FragTrap &operator=(const FragTrap &copy);

    void highFiveGuys(void);
};

#endif