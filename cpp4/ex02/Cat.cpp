#include "Cat.hpp"

Cat::Cat()
{
    brain = new Brain();
    std::cout << "Constructor_Cat: wow a brain" << std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Destructor_Cat: I have no brain now" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    brain = new Brain();
    std::cout << "Copy_Constructor_Cat: I have a brain now" << std::endl;
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
