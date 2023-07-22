#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        const std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator = (RobotomyRequestForm &assing);
        ~RobotomyRequestForm();

        RobotomyRequestForm(const std::string &target);
        void execute(const Bureaucrat &executor) const;
};

#endif