#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	{
		Bureaucrat b("Arthur", 137);
		ShrubberyCreationForm f("Home");
		std::cout << std::endl << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(&f);
		b.executeForm(f);
		std::cout << std::endl << f << std::endl;
	}
	std::cout << std::endl << "-----------------------------------------------------------------" << std::endl << std::endl;
	{
		Bureaucrat b("Doctor", 45);
		RobotomyRequestForm f("Patient");
		std::cout << std::endl << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(&f);
		b.executeForm(f);
		std::cout << std::endl << f << std::endl;
	}
	std::cout << std::endl << "-----------------------------------------------------------------" << std::endl << std::endl;
	{
		Bureaucrat b("Zaphod", 1);
		PresidentialPardonForm f("Citizen");
		std::cout << std::endl << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(&f);
		b.executeForm(f);
		std::cout << std::endl << f << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
