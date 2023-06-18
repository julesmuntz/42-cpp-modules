#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(150), _execGrade(150), _isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(Form const &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other)
{
	std::cout << "Form assignation operator called" << std::endl;
	_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destructor called" << std::endl;
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

bool Form::getSigned() const
{
	return this->_isSigned;
}

Form::Form(std::string const name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	std::cout << "Form " << name << " (grade " << signGrade << ") constructor called" << std::endl;
	try
	{
		if (signGrade < 1)
			throw Form::GradeTooHighException();
		else if (signGrade > 150)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator << (std::ostream &out, Form const &other)
{
	if (other.getSigned() == true)
		std::cout << "Form \"" << other.getName() << "\" is \033[0;36mSIGNED\033[0;0m." << std::endl;
	else
		std::cout << "Form \"" << other.getName() << "\" is \033[0;35mUNSIGNED\033[0;0m." << std::endl;
	std::cout << "Grade " << other.getSignGrade() << " is required to sign it." << std::endl;
	std::cout << "And grade " << other.getExecGrade() << " is required to execute it." << std::endl;
	return out;
}

void Form::setSigned()
{
	this->_isSigned = true;
}

void Form::beSigned(Bureaucrat *b)
{
	if (b->getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}
