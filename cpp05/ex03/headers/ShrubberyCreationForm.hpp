#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string target);

	void execute(Bureaucrat const &executor) const;

private:
	std::string _target;
};
