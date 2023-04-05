#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
	public:
		HumanB(void);
		HumanB(std::string);
		~HumanB(void);
		void attack();
		void setWeapon(Weapon &weapon);
	private:
		Weapon *_weapon;
		std::string _name;
};

#endif