#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NONAMECLAP")
{
    _name = "NONAMECLAP";
    std::cout << "Diamondtrap constructor called" << std::endl;
    _HitPoints = FragTrap::_HitPoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
     std::cout << "Diamondtrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
    _name = name;
    std::cout << "Diamondtrap constructor called" << std::endl;
    _HitPoints = FragTrap::_HitPoints;
    _EnergyPoints = ScavTrap::_EnergyPoints;
    _AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    _name = copy._name + "_clap_trap";
    _HitPoints = copy._HitPoints;
    _EnergyPoints = copy._EnergyPoints;
    _AttackDamage = copy._AttackDamage;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "This is Diamondtrap " << _name << " and " << "aka. " << ClapTrap::_name << std::endl;
}