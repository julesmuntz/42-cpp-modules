#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
					Dog();
					Dog(Dog const &other);
					~Dog();
		Dog			&operator=(Dog const &other);

virtual	void		makeSound() const;

	private:
		Brain		*_brain;
};

#endif