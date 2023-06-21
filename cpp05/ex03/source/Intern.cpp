#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	_formList = NULL;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << "Intern assignation operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
	while (_formList != NULL)
	{
		Node* next = _formList->next;
		delete _formList->form;
		delete _formList;
		_formList = next;
	}
}

AForm *Intern::shrubbery(std::string target)
{
	AForm* form = new ShrubberyCreationForm(target);
	collectForm(form);
	return form;
}

AForm *Intern::robotomy(std::string target)
{
	AForm* form = new RobotomyRequestForm(target);
	collectForm(form);
	return form;
}
AForm *Intern::presidential(std::string target)
{
	AForm* form = new PresidentialPardonForm(target);
	collectForm(form);
	return form;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	try
	{
		int i;
		AForm *(Intern::*f[3])(std::string) = {&Intern::shrubbery, &Intern::robotomy, &Intern::presidential};
		std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		for (i = 0; i < 3; i++)
			if (name == form[i])
			{
				std::cout << "Intern creates " << (this->*f[i])(target)->getName() << std::endl;
				return (this->*f[i])(target);
			}
		if (i == 3)
			throw FormNotFoundException();
	}
	catch (FormNotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return NULL;
}

void Intern::collectForm(AForm* form)
{
	Node* newNode = new Node;
	newNode->form = form;
	newNode->next = _formList;
	_formList = newNode;
}
