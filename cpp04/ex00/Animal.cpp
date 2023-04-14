#include "Animal.hpp"

Animal::Animal() : _type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
	std::cout << "Animal " << this->_type << " copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &other)
{
	std::cout << "Animal " << this->_type << " copy assignment operator called" << std::endl;
	this->_type = other.getType();
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "The class \"Animal\" doesn\'t produce any sound." << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}
