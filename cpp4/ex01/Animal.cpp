#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Constructor_Animal" << std::endl;
    type = "Just Animal";
}

Animal::~Animal()
{
    std::cout << "Destructor_Animal" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Copy_Constructor_Animal" << std::endl;
    type = copy.type;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "CopyAssigment_Constructor_Animal" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Im the Animal class" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}