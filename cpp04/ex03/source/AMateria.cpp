#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
	*this = other;
	std::cout << "AMateria copy " << this->_type << " constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	(void)other;
	std::cout << "AMateria \"" << this->_type << "\" copy assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria \"" << this->_type << "\" destructor called" << std::endl;
}

AMateria::AMateria(string const &type) : _type(type)
{
	std::cout << "AMateria \"" << type << "\" constructor called" << std::endl;
}

string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
