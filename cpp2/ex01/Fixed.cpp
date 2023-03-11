#include "Fixed.hpp"

Fixed::Fixed(const int) : _fixedPointNumber(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fdnumber):_fixedPointNumber(fdnumber << _fractionalBits)
{
    
}

Fixed::~Fixed()
{
}