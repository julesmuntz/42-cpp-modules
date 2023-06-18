#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator=(Bureaucrat const &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

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

		Bureaucrat(std::string const name, int grade);

		void		incrementGrade();
		void		decrementGrade();

		void		signForm(Form *f) const;

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream &operator << (std::ostream &out, Bureaucrat const &other);
