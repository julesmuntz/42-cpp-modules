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

private:
	void collectForm(AForm *form);

	class FormNotFoundException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mThe form passed as parameter doesn\'t exist!\033[0;0m";
		}
	};

	struct Node
	{
		AForm *form;
		Node *next;
	};

	Node *_formList;
};
