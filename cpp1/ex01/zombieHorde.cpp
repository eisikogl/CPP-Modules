#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombiehord = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        zombiehord[i].setname(name);
    }

    return zombiehord;
}