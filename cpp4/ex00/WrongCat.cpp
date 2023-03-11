#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Constructor_WrongCat" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "Deststructor_WrongCat" << std::endl;

}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "Copy_Constructor_WrongCat" << std::endl;
    type = copy.type;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "CopyAssigment_Constructor_WrongCat" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "I'm an Animal of type: " << type << " and I say RRROAAARR" << std::endl;
}
