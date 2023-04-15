#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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