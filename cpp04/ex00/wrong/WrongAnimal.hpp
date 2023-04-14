#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
					WrongAnimal();
					WrongAnimal(WrongAnimal const &other);
virtual				~WrongAnimal();
		WrongAnimal	&operator=(WrongAnimal const &other);

		void		makeSound() const;
		std::string	getType() const;
					WrongAnimal(std::string type);

	protected:
		std::string	_type;
};

#endif