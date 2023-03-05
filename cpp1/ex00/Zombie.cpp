#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie named: " << _name << ", has been Destructed" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}