#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _fixedPointNumber;
    static const int _fractionalBits = 8;
public:
    Fixed(const int);
    Fixed(const float);
    ~Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator = (const Fixed &copy);
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits() const;
		void setRawBits(int const raw);
};



#endif