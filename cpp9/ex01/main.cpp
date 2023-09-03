#include "RPN.hpp"
#include <iostream>

int main(int argc,char *argv[])
{
    if(argc != 2)
        std::cout << "Error: Argument count" << std::endl;
    RPN obj;

    obj.polish(argv[1]);
}