#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "The " << _type << " barks." << std::endl;
}
