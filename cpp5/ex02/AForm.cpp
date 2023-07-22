#include "AForm.hpp"

AForm::AForm(): _gradeToSign(0), _gradeToExecute(0)
{
    
}

AForm::AForm(const AForm &copy): _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	*this = copy;
}

AForm &AForm::operator = (const AForm &assign)
{
    (void)assign;
	return *this;
}

AForm::~AForm()
{
    
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150)
        throw GradeTooLowException();
    if (gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
}

std::ostream &operator << (std::ostream &ostr, const AForm &form)
{
    ostr << form.getName() << ", Form grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << ", signed: " << form.isSigned();
    return ostr;
}