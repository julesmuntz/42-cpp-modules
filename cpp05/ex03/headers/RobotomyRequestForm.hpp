#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string target);

	void execute(Bureaucrat const &executor) const;

private:
	std::string _target;
};
