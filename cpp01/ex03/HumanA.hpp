#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(void);
		HumanA(std::string, Weapon&);
		~HumanA(void);
		void attack();
	private:
		Weapon *_weapon;
		std::string _name;
};

#endif