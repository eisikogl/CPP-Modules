#include "Zombie.hpp"

int main()
{
    Zombie zom1("ezom");
    Zombie *zom2 = newZombie("izomnewzom");
    zom2->announce();
    randomChump("zomnameann");
    delete(zom2);
}