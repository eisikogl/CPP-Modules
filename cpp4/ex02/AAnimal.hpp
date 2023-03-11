#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type;
public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal &copy);
	AAnimal &operator = (const AAnimal &copy);
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif