#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(150), _execGrade(150), _isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "Form assignation operator called" << std::endl;
	_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	// std::cout << "Form " << this->_name << " destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

bool AForm::getSigned() const
{
	return this->_isSigned;
}

AForm::AForm(std::string const name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	// std::cout << "Form " << name << " (Sign: " << signGrade << ", Exec: " << execGrade << ") constructor called" << std::endl;
	try
	{
		if (signGrade < 1)
			throw AForm::GradeTooHighException();
		else if (signGrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, AForm const &other)
{
	if (other.getSigned() == true)
		std::cout << "Form \"" << other.getName() << "\" is \033[0;36mSIGNED\033[0;0m." << std::endl;
	else
		std::cout << "Form \"" << other.getName() << "\" is \033[0;35mUNSIGNED\033[0;0m." << std::endl;
	std::cout << "Grade " << other.getSignGrade() << " is required to sign it." << std::endl;
	std::cout << "And grade " << other.getExecGrade() << " is required to execute it." << std::endl;
	return out;
}

void AForm::setSigned()
{
	this->_isSigned = true;
}

void AForm::beSigned(Bureaucrat *b)
{
	if (b->getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}
