#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Default Constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor called" << std::endl;
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl <<"I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    // void (Harl::*funcs[]) () =
    // {
    //     &Harl::debug,
    //     &Harl::info,
    //     &Harl::warning,
    //     &Harl::error
    // };
    int index = -1;
    for (size_t i = 0; i < levels->length(); i++)
    {
        if (levels[i] == level)
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
    case 0:
        std::cout << "[ " << levels[0] << " ]" << std::endl;
        this->debug();
        break;
    case 1:
        std::cout << "[ " << levels[1] << " ]" <<std::endl;
        this->info();
        break;
    case 2:
        std::cout << "[ " << levels[2] << " ]" << std::endl;
        this->warning();
        break;
    case 3:
        std::cout << "[ " << levels[3] << " ]" << std::endl;
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
        break;
    }

}