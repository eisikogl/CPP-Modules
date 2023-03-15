#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(int value);
	Fixed(float value);
    Fixed(const Fixed &copy);
    Fixed &operator = (const Fixed &copy);
    ~Fixed();

    bool operator < (const Fixed &other);
    bool operator > (const Fixed &other);
    bool operator >= (const Fixed &other);
    bool operator <= (const Fixed &other);
    bool operator == (const Fixed &other);
    bool operator != (const Fixed &other);

    Fixed operator + (const Fixed &other);
    Fixed operator - (const Fixed &other);
    Fixed operator * (const Fixed &other);
    Fixed operator / (const Fixed &other);

    Fixed &operator ++();
    Fixed operator ++(int);
    Fixed &operator --();
    Fixed operator --(int);

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator << (std::ostream &ostr,  Fixed const &fixed);


#endif