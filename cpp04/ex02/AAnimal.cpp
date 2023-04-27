#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
	*this = other;
	std::cout << "AAnimal " << this->_type << " copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->_type << " destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	this->_type = other._type;
	std::cout << "AAnimal " << this->_type << " copy assignment operator called" << std::endl;
	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout << "The class \"AAnimal\" doesn\'t produce any sound." << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal " << this->_type << " constructor called" << std::endl;
}
