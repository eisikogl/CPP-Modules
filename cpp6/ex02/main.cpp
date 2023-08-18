#include "Base.hpp"
#include <iostream>

int main() 
{
    srand(time(NULL));
    Base *obj = generate();
    Base *o = generate();
    identify(o);
    identify(*o);
    identify(obj);
    identify(*obj);

    delete o;
    delete obj;
    return 0;
}
