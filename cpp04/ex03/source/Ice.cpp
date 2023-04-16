#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria("ice")
{
	*this = other;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
