#ifndef POINT_HPP
#define POINT_HPP


#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(const float a, const float b);
    Point(const Point &copy);
    ~Point();
    Point &operator=(const Point &copy);

    const Fixed &getX() const;
    const Fixed &getY() const;

};

float triangleArea(Point p1, Point p2, Point p3);
bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif