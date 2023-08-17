#include "Base.hpp"
#include <iostream>

int main() 
{
    Base* obj = generate();
    //identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
