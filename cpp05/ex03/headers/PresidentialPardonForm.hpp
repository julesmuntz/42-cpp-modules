#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string target);

	void execute(Bureaucrat const &executor) const;

	std::string name;

private:
	std::string _target;
};
