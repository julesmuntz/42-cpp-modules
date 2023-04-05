#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(void);
		~HumanA(void);
		void attack();
	private:
		std::string _weapon;
		std::string _name;
};

#endif