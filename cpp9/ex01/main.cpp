#include "RPN.hpp"
#include <iostream>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Error: Argument count" << std::endl;
        return 0;
    }
    RPN obj;

    if(checkinput(argv[1]))
    {
        obj.polish(argv[1]);
    }
    return 0;
}