#include "Point.hpp"

Point::Point() : _x(0),_y(0)
{

}

Point::Point(const float a,const float b): _x(a),_y(b)
{

}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
	*this = copy;
}

Point &Point::operator = (const Point &assign)
{
	(void)assign;
	return *this;
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
	return this->_x;
}

const Fixed &Point::getY() const
{
	return this->_y;
}
