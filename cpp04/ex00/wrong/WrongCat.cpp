#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "The " << _type << " meows." << std::endl;
}
