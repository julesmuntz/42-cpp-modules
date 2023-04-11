#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
					ScavTrap();
					ScavTrap(ScavTrap const &other);
		ScavTrap	&operator=(ScavTrap const &other);
					ScavTrap(std::string name);
					~ScavTrap();

		void		attack(std::string const &target);
		void		guardGate();
};

#endif