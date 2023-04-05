#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

std::string const &Weapon::getType()
{
	std::string const &ref = this->_type;
	return ref;
}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}