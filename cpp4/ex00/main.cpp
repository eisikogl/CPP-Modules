#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal *aPtr = new Animal();
    // aPtr->makeSound();

    // aPtr = new Dog();
    // aPtr->makeSound();

    // aPtr = new Cat();
    // aPtr->makeSound();

    // std::cout << std::endl;

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *k = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    k->makeSound();

    delete meta;
    delete j;
    delete i;
    delete k;

    return 0;
}
