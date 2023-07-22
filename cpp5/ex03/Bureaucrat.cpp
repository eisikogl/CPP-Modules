#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &assign)
{
    (void)assign;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator << (std::ostream &ostr, const Bureaucrat &bureaucrat)
{
    ostr << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return ostr;
}
