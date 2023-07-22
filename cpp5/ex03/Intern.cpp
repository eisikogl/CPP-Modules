#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator = (const Intern &assign)
{
    (void)assign;
    return *this;
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] =
    {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };

    AForm *forms[] =
    {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)
    };
    
    for (int i = 0; i < (int)formNames->length(); i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i];
        }
    }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return NULL;
}