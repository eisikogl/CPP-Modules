#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
    Brain();
    virtual ~Brain();
    Brain(const Brain &copy);
	Brain &operator = (const Brain &copy);
    std::string ideas[100];
};

#endif