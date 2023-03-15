#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    ~FragTrap();
    FragTrap(std::string);
    FragTrap(const FragTrap &copy);
    FragTrap &operator=(const FragTrap &copy);

    void highFivesGuys(void);
};

#endif