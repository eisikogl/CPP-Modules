#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator = (ShrubberyCreationForm &assing);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string &target);
        void execute(const Bureaucrat &executor) const;
};

#endif