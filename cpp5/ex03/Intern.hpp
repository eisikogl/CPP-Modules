#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern &operator = (const Intern &assigment);
        Intern(const Intern &copy);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
};

#endif