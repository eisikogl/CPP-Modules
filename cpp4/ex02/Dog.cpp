#include "Dog.hpp"


Dog::Dog()
{
    std::cout << "Constructor_Dog: Wow a Brain"<< std::endl;
    brain = new Brain();
    type = "Dog";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor_Dog: I have no Brain now" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    brain = new Brain();
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
