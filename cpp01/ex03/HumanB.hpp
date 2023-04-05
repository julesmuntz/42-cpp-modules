#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(void);
		~HumanB(void);
		void attack();
	private:
		std::string _weapon;
		std::string _name;
};

#endif