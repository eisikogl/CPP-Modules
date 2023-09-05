#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

//Take arguments, parse arguments,store parsed arguments as integers,sort arguments, keep sorting time
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout << "Invalid Argument count" << std::endl;
        return 0;
    }
    std::deque<int> input;

    for(int i = 1;i < argc;i++)
    {
        int value = std::atoi(argv[i]);
        input.push_back(value);
    }
    
    PmergeMe arguments(*argv);
}