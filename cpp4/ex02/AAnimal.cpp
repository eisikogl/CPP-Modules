#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Constructor_AAnimal" << std::endl;
    type = "Just AAnimal";
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor_AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "Copy_Constructor_AAnimal" << std::endl;
    type = copy.type;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    std::cout << "CopyAssigment_Constructor_AAnimal" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << "Im the AAnimal class" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}