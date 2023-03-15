#include "Point.hpp"

int main(void)
{
    {
        const Point a;
        const Point b(10, 0);
        const Point c(0, 10);
        const Point point(1, 1);

        if (bsp(a, b, c, point) == true)
            std::cout << "YES!" << std::endl;
        else
            std::cout << "NO!" << std::endl;
    }

    {
        Point a(-1.5, -1.5);
        Point b(2.5, 2.5);
        Point c(-1, -2);
        Point point(8.5, -9);

        if (bsp(a, b, c, point) == true)
            std::cout << "YES!" << std::endl;
        else
            std::cout << "NO!" << std::endl;
    }

    {
        const Point a;
        const Point b(10, 5);
        const Point c(5, 10);
        const Point point(1, 1);

        if (bsp(a, b, c, point) == true)
            std::cout << "YES!" << std::endl;
        else
            std::cout << "NO!" << std::endl;
    }

	return (0);
}