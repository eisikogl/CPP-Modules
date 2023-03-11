#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Constructor_WrongAnimal" << std::endl;
    type = "Just WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor_WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "Copy_Constructor_WrongAnimal" << std::endl;
    type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "CopyAssigment_Constructor_WrongAnimal" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Im the WrongAnimal class" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}