#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *brain;
public:
    Dog();
    ~Dog();
    Dog(const Dog &copy);
    Dog &operator = (const Dog &copy);
    void makeSound() const;
};



#endif