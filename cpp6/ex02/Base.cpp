#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <typeinfo>


Base* generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    switch (random) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return nullptr;
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p) 
{
    try 
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &bc){}

    try 
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast &bc){}

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &bc){}
}

