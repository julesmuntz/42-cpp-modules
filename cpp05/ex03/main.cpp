#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl << "-----------------------------------------------------------------" << std::endl << "|\t" << std::endl;
	{
		std::cout << "|\t";
		Intern i;
		std::cout << "|\t";
		i.makeForm("shrubbery creation", "Target 1");
		std::cout << "|\t";
	}
	std::cout << "|\t" << std::endl << "-----------------------------------------------------------------" << std::endl << "|\t" << std::endl;
	{
		std::cout << "|\t";
		Intern i;
		std::cout << "|\t";
		i.makeForm("robotomy request", "Target 2");
		std::cout << "|\t";
	}
	std::cout << "|\t" << std::endl << "-----------------------------------------------------------------" << std::endl << "|\t" << std::endl;
	{
		std::cout << "|\t";
		Intern i;
		std::cout << "|\t";
		i.makeForm("presidential pardon", "Target 3");
		std::cout << "|\t";
	}
	std::cout << "|\t" << std::endl << "-----------------------------------------------------------------" << std::endl << "|\t" << std::endl;
	{
		std::cout << "|\t";
		Intern i;
		std::cout << "|\t";
		i.makeForm("the answer to the universe", "Target 4");
		std::cout << "|\t";
	}
	std::cout << "|\t" << std::endl << "-----------------------------------------------------------------" << std::endl << std::endl;
	return 0;
}
