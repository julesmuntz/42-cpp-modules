#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
using std::string;

class Character : public ICharacter
{
	public:
						Character();
						Character(Character const &other);
		Character		&operator=(Character const &other);
virtual					~Character();

						Character(string name);
		string const	&getName() const;
		void			equip(AMateria *m);
		void			unequip(int idx);
		void			use(int idx, ICharacter &target);

	private:
		AMateria		*_inventory[4];
		string			_name;
};

#endif
