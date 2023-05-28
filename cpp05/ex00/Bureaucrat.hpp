#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator=(Bureaucrat const &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		GradeTooHighException();
		void		GradeTooLowException();

	private:
		std::string const	_name;
		int					_grade;
};
