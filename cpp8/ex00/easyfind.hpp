#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
int easyfind(T &container, int value)
{
   typename T::iterator it = std::find(container.begin(), container.end(), value);
   if(it != container.end())
        return std::distance(container.begin(),it);

    throw std::runtime_error("Value not found in Container");
}

#endif