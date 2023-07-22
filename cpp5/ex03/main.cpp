#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat bureaucrat("Casper", 86);
        AForm *shrubberyCreationForm;
        AForm *robotomyRequestForm;
        AForm *presidentialPardonForm;

        shrubberyCreationForm = someRandomIntern.makeForm("shrubbery creation", "Bender");
        robotomyRequestForm = someRandomIntern.makeForm("robotomy request", "Home");
        presidentialPardonForm = someRandomIntern.makeForm("presidential pardon", "Office");

        std::cout << "\n--------------- Form 1 (Shrubbery) ---------------" << std::endl;
        bureaucrat.signForm(*shrubberyCreationForm);
        bureaucrat.executeForm(*shrubberyCreationForm);
        std::cout << "\n--------------- Form 2 (Robotomy)  ---------------" << std::endl;
        bureaucrat.signForm(*robotomyRequestForm);
        bureaucrat.executeForm(*robotomyRequestForm);
        std::cout << "\n--------------- Form 3 (President) ---------------" << std::endl;
        bureaucrat.signForm(*presidentialPardonForm);
        bureaucrat.executeForm(*presidentialPardonForm);

        delete shrubberyCreationForm;
        delete robotomyRequestForm;
        delete presidentialPardonForm;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}