#include "Base.hpp"
#include <iostream>

int main() {
    srand(time(0)); // Seed for randomness

    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
