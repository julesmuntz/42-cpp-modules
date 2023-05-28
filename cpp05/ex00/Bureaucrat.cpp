#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::GradeTooHighException()
{
	if (Bureaucrat::getGrade() < 1)
		std::cout << "Grade too high" << std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	if (Bureaucrat::getGrade() > 150)
		std::cout << "Grade too low" << std::endl;
}
