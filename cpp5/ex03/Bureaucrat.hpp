#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{ 
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator = (const Bureaucrat &assign);
		~Bureaucrat();
        
        Bureaucrat(std::string name, int grade);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(const AForm& form) const;  

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Bureaucrat grade is too high";
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Bureaucrat grade is too low";
                }
        };
};

std::ostream &operator << (std::ostream &ostr, const Bureaucrat &bureaucrat);

#endif