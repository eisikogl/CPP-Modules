#include "Base.hpp"
#include <iostream>
#include <cstdlib>


Base* generate(void)
{
    int random = rand() % 3;
    switch (random) 
    {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return nullptr;
}

void identify(Base *p) 
{
    std::cout << "Im a Pointer to derived class my type is: " << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p) 
{
    std::cout << "Im referenced to derived class my type is: " << std::endl;
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &cast){}

    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast &cast){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &cast){}
}

