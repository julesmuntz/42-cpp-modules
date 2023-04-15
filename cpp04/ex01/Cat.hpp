#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
					Cat();
					Cat(Cat const &other);
					~Cat();
		Cat			&operator=(Cat const &other);

virtual	void		makeSound() const;

	private:
		Brain		*_brain;
};

#endif