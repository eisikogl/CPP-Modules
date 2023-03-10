#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap eno("Eno");
    ClapTrap mev("Mev");
    ScavTrap evil("EvilScav");
    ScavTrap evil2("MelivScrap");

    evil.guardGate();
    eno.beRepaired(20);
    evil.attack(eno.getname());
    eno.takeDamage(evil.getAttackDamage());
    evil2.attack(evil.getname());
    evil.takeDamage(evil2.getAttackDamage());
    mev.setAttackDamage(100);
    evil.beRepaired(10);
    mev.attack(evil.getname());
    evil.takeDamage(mev.getAttackDamage());
}