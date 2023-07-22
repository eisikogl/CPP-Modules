#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        const std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &assign);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string &target);
        void execute(const Bureaucrat &executor) const;
};

#endif