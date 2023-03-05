#include "Zombie.hpp"

int main()
{
    int i = 10;
    Zombie *myZombies = zombieHorde(i,"enes");
    for(int j = 0; j < i; j++)
    {
        myZombies[j].announce();
    }
    
    delete[] myZombies;
}