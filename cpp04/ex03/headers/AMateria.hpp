#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"
using std::string;

class ICharacter;

class AMateria
{
	public:
						AMateria();
						AMateria(AMateria const &other);
		AMateria		&operator=(AMateria const &other);
virtual 				~AMateria();

						AMateria(string const &type);
		string const	&getType() const;
virtual	AMateria		*clone() const = 0;
virtual	void			use(ICharacter &target);

	protected:
		string			_type;
};

#endif
