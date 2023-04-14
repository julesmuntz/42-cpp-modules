#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "WrongAnimal " << this->_type << " copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << this->_type << " destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "WrongAnimal " << this->_type << " copy assignment operator called" << std::endl;
	this->_type = other.getType();
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "The class \"WrongAnimal\" doesn\'t produce any sound." << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}
