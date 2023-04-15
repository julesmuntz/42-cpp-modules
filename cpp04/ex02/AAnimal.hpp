#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
					AAnimal();
					AAnimal(AAnimal const &other);
virtual				~AAnimal();
		AAnimal		&operator=(AAnimal const &other);

virtual	void		makeSound() const = 0;
		std::string	getType() const;
					AAnimal(std::string type);

	protected:
		std::string	_type;
};

#endif