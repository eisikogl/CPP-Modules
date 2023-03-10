#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedPointNumber;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &copy);
    ~Fixed();
	Fixed &operator = (const Fixed &f);
    int getRawBits() const;
    void setRawBits( int const);
};



#endif