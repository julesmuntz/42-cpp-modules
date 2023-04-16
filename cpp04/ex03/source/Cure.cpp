#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria("cure")
{
	*this = other;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
