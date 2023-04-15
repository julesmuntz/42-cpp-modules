#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
	std::cout << "AAnimal " << this->_type << " copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->_type << " destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	std::cout << "AAnimal " << this->_type << " copy assignment operator called" << std::endl;
	this->_type = other.getType();
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
