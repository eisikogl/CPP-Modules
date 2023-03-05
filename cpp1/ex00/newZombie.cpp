#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newzom = new Zombie(name);
	return newzom;
}