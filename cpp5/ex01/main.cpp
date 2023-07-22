#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form f("Form 1", 0, 100);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form f("Form 2", 151, 100);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form f("Form 3", 100, 0);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form f("Form 4", 100, 151);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    Form f("Form 5", 100, 100);
    std::cout << f << std::endl;

    Bureaucrat b1("Bureaucrat 1", 1);
    Bureaucrat b2("Bureaucrat 2", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try
    {
        b1.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        b2.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    b1.signForm(f);
    std::cout << f << std::endl;
    b2.signForm(f);
    std::cout << f << std::endl;

    return 0;
}
