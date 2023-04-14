#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
					Animal();
					Animal(Animal const &other);
virtual				~Animal();
		Animal		&operator=(Animal const &other);

virtual	void		makeSound() const;
		std::string	getType() const;
					Animal(std::string type);

	protected:
		std::string	_type;
};

#endif