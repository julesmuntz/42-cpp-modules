#include "Intern.hpp"
#include <typeinfo>

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	std::cout << "Intern assignation operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::shrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::presidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	try
	{
		AForm *(Intern::*f[3])(std::string) = {&Intern::shrubbery, &Intern::robotomy, &Intern::presidential};
		std::string form[3] = {"shrubbery creation", "robotomy request ", "presidential pardon"};
		for (int i = 0; i < 3; i++)
			if (name == form[i])
				return (this->*f[i])(target);
		std::cout << "Intern creates " << name << std::endl;
	}
}
