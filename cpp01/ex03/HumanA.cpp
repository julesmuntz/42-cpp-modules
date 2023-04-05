#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name)
{
	this->_weapon = &weapon;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks using \"" << this->_weapon->getType() << "\"" << std::endl;
}
