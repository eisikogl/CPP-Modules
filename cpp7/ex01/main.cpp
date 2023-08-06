// main.cpp
#include "iter.hpp"
#include <iostream>
#include <string>

// Sample functions to be used with iter
void printInt(int const &num) {
    std::cout << num << " ";
}

void printString(std::string const &str) {
    std::cout << str << " ";
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"apple", "banana", "cherry"};

    std::cout << "Integers: ";
    iter(intArr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Strings: ";
    iter(strArr, 3, printString);
    std::cout << std::endl;

    return 0;
}
