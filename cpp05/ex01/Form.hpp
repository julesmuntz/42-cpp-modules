#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(Form const &other);
        Form	&operator=(Form const &other);
        ~Form();

        std::string	getName() const;
        int			getSignGrade() const;
        int			getExecGrade() const;
        bool		getSigned() const;

        Form(std::string const name, int signGrade, int execGrade);

        void		beSigned(Bureaucrat *b);
        void        setSigned();

    private:
        std::string const	_name;
        int const			_signGrade;
        int const			_execGrade;
        bool				_isSigned;

        class		GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "\033[0;31mgrade is too high!\033[0;0m";
                }
        };

        class		GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "\033[0;31mgrade is too low!\033[0;0m";
                }
        };
};

std::ostream &operator << (std::ostream &out, Form const &other);
