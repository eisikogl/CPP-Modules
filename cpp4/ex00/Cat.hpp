#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
    /* data */
public:
    Cat();
    ~Cat();
    Cat(const Cat &copy);
	Cat &operator = (const Cat &copy);
    void makeSound() const;
};


#endif