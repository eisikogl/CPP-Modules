#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "constructor_Brain" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Copy constructor called_Brain" << std::endl;
    for (int i = 0; i < 100; i++) 
    {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain::~Brain()
{
    std::cout << "Destructor_Brain" << std::endl;
}

Brain& Brain::operator=(const Brain &copy)
{
    if (this != &copy) 
    {
        for (int i = 0; i < 100; i++) 
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}