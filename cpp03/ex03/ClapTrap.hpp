#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

typedef unsigned int uInt;

class ClapTrap
{
	public:
					ClapTrap();
					ClapTrap(ClapTrap const &other);
		ClapTrap	&operator=(ClapTrap const &other);
					ClapTrap(std::string name);
					~ClapTrap();

		void		attack(std::string const &target);
		void		takeDamage(uInt amount);
		void		beRepaired(uInt amount);

		void		printInfo();
		void		setAttackDamage(uInt attackDamage);
		void		setEnergyPoints(uInt energyPoints);

	protected:
		std::string	_name;
		uInt		_hitPoints;
		uInt		_energyPoints;
		uInt		_attackDamage;
static	ClapTrap	*_head;
		ClapTrap	*_next;
		std::string	_className;
};

#endif