#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Constructor_Cat" << std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Destructor_Cat" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Copy_Constructor_Cat" << std::endl;
    type = copy.type;
}

Cat& Cat::operator=(const Cat &copy)
{
    std::cout << "CopyAssigment_Constructor_Cat" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "I'm an Animal of type: " << type << " and I say MAIWWWW MAIWW" << std::endl;
}
