#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type)
{
	std::cout << "WrongAnimal " << this->_type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "WrongAnimal " << this->_type << " copy assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
}

std::string	WrongAnimal::getType() const
{
	return _type;
}
