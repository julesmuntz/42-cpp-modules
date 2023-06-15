#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(0)
{
	std::cout << "Bureaucrat " << name << " (grade " << grade << ") constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator << (std::ostream &out, Bureaucrat const &other)
{
	if (other.getGrade() >= 1 && other.getGrade() <= 150)
		out << "\033[0;32m" << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\033[0;0m" << std::endl;
	return out;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
