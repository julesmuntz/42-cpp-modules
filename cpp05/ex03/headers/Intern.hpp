#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();

	AForm *makeForm(std::string name, std::string target);

	AForm *shrubbery(std::string target);
	AForm *robotomy(std::string target);
	AForm *presidential(std::string target);
};
