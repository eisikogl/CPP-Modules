#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), _target(copy._target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &assign)
{
    (void)assign;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->isSigned() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
