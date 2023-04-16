#include "Character.hpp"

Character::Character() : _name("default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &other) : _name(other._name)
{
	std::cout << "Character " << this->_name << " copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i];
	*this = other;
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Character " << this->_name << " copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character \"" << this->_name << "\" destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

Character::Character(string name) : _name(name)
{
	std::cout << "Character \"" << name << "\" constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
			this->_inventory[i] = NULL;
			break;
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Error: Invalid slot (index " << idx << ") for " << this->_name << "\'s inventory" << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "Error: Empty slot (index " << idx << ") for " << this->_name << "\'s inventory" << std::endl;
		return;
	}
	std::cout << "Character \"" << this->_name << "\" uses \"" << this->_inventory[idx]->getType() << "\" on target \"" << target.getName() << "\"" << std::endl;
	this->_inventory[idx]->use(target);
}

string const &Character::getName() const
{
	return this->_name;
}
