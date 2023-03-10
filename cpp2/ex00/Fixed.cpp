#include "Fixed.hpp"

Fixed::Fixed(const Fixed &copy) : _fixedPointNumber(copy.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed() : _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignation operator called" << std::endl;
    if (this != &other)
    {
        _fixedPointNumber = other._fixedPointNumber;
    }
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointNumber = raw;
}
