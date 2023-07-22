#include "Form.hpp"

Form::Form() : _grade_to_sign(0), _grade_to_execute(0)
{

}

Form::Form(const Form &copy) : _grade_to_sign(copy.getGradeToSign()), _grade_to_execute(copy.getGradeToExecute())
{
    *this = copy;
}

Form &Form::operator = (const Form &assign)
{
    (void)assign;
    return *this;
}

Form::~Form()
{

}

Form::Form(std::string name,int gradeToSign,int gradeToExecute): _name(name), _is_signed(false), _grade_to_sign(gradeToSign),_grade_to_execute(gradeToExecute)
{
    if(gradeToSign < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150)
        throw GradeTooLowException();
    if(gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToExecute > 150)
        throw GradeTooLowException(); 
}

std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _is_signed;
}

int Form::getGradeToSign() const
{
    return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
    return _grade_to_execute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw GradeTooLowException();
    _is_signed = true;
}

std::ostream &operator << (std::ostream &ostr,const Form &form)
{
    ostr << form.getName() << ", Form grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << ", signed: " << form.isSigned();
    return ostr; 
}