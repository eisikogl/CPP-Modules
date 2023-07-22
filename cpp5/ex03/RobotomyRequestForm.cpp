#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), _target(copy._target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm &assign)
{
    (void)assign;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy Request Form", 72, 45), _target(target)
{

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    srand(time(NULL));
    if (std::rand() % 2 + 0 == 0)
        std::cout << "* some drilling noises * " << _target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
}
