#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
		if (executor.getGrade() <= 137 && executor.getGrade() >= 1)
		{
			std::string filename = this->_target + "_shrubbery";
			std::ofstream file(filename.c_str());
			file << "               ,@@@@@@@," << std::endl
				 << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
				 << "    ,&&%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
				 << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
				 << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
				 << "   %&&%/ %&%&%&@@\\ V /@@' `88\\8 `/88'" << std::endl
				 << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
				 << "       |o|        | |         | |" << std::endl
				 << "       |.|        | |         | |" << std::endl
				 << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
		}
		else
			throw Bureaucrat::GradeTooLowException();
}
