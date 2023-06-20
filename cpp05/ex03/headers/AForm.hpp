#pragma once

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm() = 0;

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	AForm(std::string const name, int signGrade, int execGrade);

	void beSigned(Bureaucrat *b);
	void setSigned();

	virtual void execute(Bureaucrat const &executor) const = 0;

private:
	std::string const _name;
	int const _signGrade;
	int const _execGrade;
	bool _isSigned;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mgrade is too high!\033[0;0m";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mgrade is too low!\033[0;0m";
		}
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &other);
