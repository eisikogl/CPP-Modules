#include "DiamondTrap.hpp"

int main()
{
    {
        std::cout << "----------------------" << std::endl;
        ClapTrap clapTrap("Clap");
        clapTrap.attack("Clap's Enemy");
        clapTrap.takeDamage(5);
        clapTrap.beRepaired(3);
        clapTrap.beRepaired(5);
        clapTrap.takeDamage(10);
    } 

    {
        std::cout << "----------------------" << std::endl;
        ScavTrap scavTrap("Scav");
        scavTrap.attack("Scav's Enemy");
        scavTrap.takeDamage(5);
        scavTrap.beRepaired(3);
        scavTrap.guardGate();
        scavTrap.beRepaired(5);
        scavTrap.takeDamage(10);
    }

    {
        std::cout << "----------------------" << std::endl;
        FragTrap fragTrap("Frag");
        fragTrap.attack("Frag's Enemy");
        fragTrap.takeDamage(5);
        fragTrap.beRepaired(3);
        fragTrap.highFivesGuys();
        fragTrap.beRepaired(5);
        fragTrap.takeDamage(10);
    }

    {
        std::cout << "----------------------" << std::endl;
        DiamondTrap diamondTrap("Diamond");
        diamondTrap.attack("Diamond's Enemy");
        diamondTrap.takeDamage(5);
        diamondTrap.beRepaired(3);
        diamondTrap.attack("Diamond's Enemy");
        diamondTrap.whoAmI();
        diamondTrap.beRepaired(5);
        diamondTrap.takeDamage(10);
    }
    return 0;
}