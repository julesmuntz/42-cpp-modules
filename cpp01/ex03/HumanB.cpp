#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(void)
{
}

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks using \"" << this->_weapon->getType() << "\"" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}