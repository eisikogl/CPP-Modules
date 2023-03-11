#include "Dog.hpp"


Dog::Dog()
{
    std::cout << "Constructor_Dog" << std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Destructor_Dog" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Copy_Constructor_Dog" << std::endl;
    type = copy.type;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "CopyAssigment_Constructor_Dog" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "I'm an Animal of type: " << type << " and I say WUFF WUFF" << std::endl;

}
