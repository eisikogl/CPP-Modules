#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Casper", 1);
        ShrubberyCreationForm shrubberyCreationForm("Shrubbery");
        RobotomyRequestForm robotomyRequestForm("Robotomy");
        PresidentialPardonForm presidentialPardonForm("President");

        std::cout << "\n--------------- Form 1 (Shrubbery) ---------------" << std::endl;
        bureaucrat.signForm(shrubberyCreationForm);
        bureaucrat.executeForm(shrubberyCreationForm);
        std::cout << "\n--------------- Form 2 (Robotomy)  ---------------" << std::endl;
        bureaucrat.signForm(robotomyRequestForm);
        bureaucrat.executeForm(robotomyRequestForm);
        std::cout << "\n--------------- Form 3 (President) ---------------" << std::endl;
        bureaucrat.signForm(presidentialPardonForm);
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}