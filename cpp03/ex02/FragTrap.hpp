#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
					FragTrap();
					FragTrap(FragTrap const &other);
		FragTrap	&operator=(FragTrap const &other);
					FragTrap(std::string name);
					~FragTrap();

		void		attack(std::string const &target);
		void		highFivesGuys(void);
};

#endif