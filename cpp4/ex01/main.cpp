#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    Animal *an[10];
    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            an[i] = new Cat();
        else
            an[i] = new Dog();
    }
    for (size_t i = 0; i < 5; i++)
    {
        delete an[i];
    }
    return 0;
}