#include "Fixed.hpp"

/*----Constructors-----*/

Fixed::Fixed() : _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fdnumber):_fixedPointNumber(fdnumber << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float _value):_fixedPointNumber(roundf(_value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &Copy)
{
	_fixedPointNumber = Copy._fixedPointNumber;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*----Constructors-----*/
/*----Member Functions--*/

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointNumber / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointNumber >> _fractionalBits;
}

/*----Member Functions--*/

std::ostream &operator << (std::ostream &ostr, Fixed const &fixed)
{
	return ostr << fixed.toFloat();
}
