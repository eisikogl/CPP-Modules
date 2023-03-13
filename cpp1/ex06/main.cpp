#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	Harl hrl;
	if (argc == 1)
	{
		std::string inp;
		std::cout << "Please enter a status : ";
		std::cin >> inp;
		hrl.complain(inp);
	}
	else
	{
		hrl.complain(argv[1]);
	}
}