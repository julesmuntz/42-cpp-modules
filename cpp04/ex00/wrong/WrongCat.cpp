#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "The " << _type << " meows." << std::endl;
}
