#include "Point.hpp"

float triangleArea(Point p1, Point p2, Point p3)
{         //find area of triangle formed by p1, p2 and p3
   return (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) - (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat()) / 2.0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool has_neg, has_pos;
    Fixed p1 = triangleArea(point,b,c);
    Fixed p2 = triangleArea(a,point,c);
    Fixed p3 = triangleArea(a,b,point);

    has_neg = (p1 < 0) || (p2 < 0) || (p3 < 0);
    has_pos = (p1 > 0) || (p2 > 0) || (p3 > 0);

    return !(has_neg && has_pos);
}