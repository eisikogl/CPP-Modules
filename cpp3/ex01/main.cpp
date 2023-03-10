#include "ClapTrap.Hpp"

int main()
{
    ClapTrap eno("Eno");
    ClapTrap mev("Mev");

    eno.setAttackDamage(2);
    eno.attack(mev.getname());
    mev.takeDamage(eno.getAttackDamage());
    mev.beRepaired(1);
    mev.setAttackDamage(10000);
    mev.attack(eno.getname());
    eno.takeDamage(mev.getAttackDamage());
}