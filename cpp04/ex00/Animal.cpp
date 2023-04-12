#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
	std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &other)
{
	std::cout << "Animal " << this->_type << " copy assignment operator called" << std::endl;
	_type = other._type;
	return *this;
}

void	Animal::makeSound() const
{
}

std::string	Animal::getType() const
{
	return _type;
}
