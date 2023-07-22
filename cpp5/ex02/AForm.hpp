#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
		AForm(const AForm &copy);
		AForm &operator = (const AForm &assign);
		virtual ~AForm();

        AForm(std::string name, int gradeToSign, int gradeToExecute);
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
        
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form grade is too high";
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form grade is too low";
                }
        };

        class NotSignedException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form not signed";
                }
        };

        class GradeTooLowToExecuteException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Bureaucrat's grade too low to execute form";
                }
        };
};

std::ostream &operator << (std::ostream &ostr, AForm const &form);

#endif