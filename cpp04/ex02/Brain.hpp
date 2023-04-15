#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
				Brain();
				Brain(Brain const &other);
		Brain	&operator=(Brain const &other);
				~Brain();

		std::string	_ideas[100];
};

#endif