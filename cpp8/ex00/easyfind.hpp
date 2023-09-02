#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
int easyfind(T &container, int value)
{
    for(size_t i = 0; i < container.size();i++)
    {
        if(container[i] == value)
            return i;
    }
    throw std::runtime_error("Value not found in Container");
}

#endif