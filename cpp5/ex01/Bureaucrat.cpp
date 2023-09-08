#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
}


Bureaucrat &Bureaucrat::operator = (const Bureaucrat &assign)
{
    if (this != &assign)
    {
        grade = assign.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name), grade(_grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
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

void Bureaucrat::signForm(Form &form)
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

std::ostream &operator << (std::ostream &ostr, const Bureaucrat &bureaucrat)
{
    ostr << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return ostr;
}