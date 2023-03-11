#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
   //AAnimal ani = new AAnimal();

   // Animal *aPtr = new Animal();
    // aPtr->makeSound();

    // aPtr = new Dog();
    // aPtr->makeSound();

    // aPtr = new Cat();
    // aPtr->makeSound();

    // std::cout << std::endl;

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();

    delete j;
    delete i;

    return 0;
}