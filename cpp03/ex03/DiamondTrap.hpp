#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
					DiamondTrap();
					DiamondTrap(DiamondTrap const &other);
		DiamondTrap	&operator=(DiamondTrap const &other);
					DiamondTrap(std::string name);
					~DiamondTrap();

		void		attack(std::string const &target);
		void		whoAmI();

	private:
		std::string	_name;
};

#endif