#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = other._name;
	return *this;
}

ClapTrap *ClapTrap::_head = NULL;

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _next(NULL)
{
	std::cout << "Constructor called" << std::endl;
	if (!_head)
		_head = this;
	else
	{
		ClapTrap *current = _head;
		while (current->_next)
			current = current->_next;
		current->_next = this;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
	if (_head == this)
		_head = _next;
	else
	{
		ClapTrap *current = _head;
		while (current && current->_next != this)
			current = current->_next;
		if (current)
			current->_next = _next;
	}
}

void	ClapTrap::attack(std::string const &target)
{
	ClapTrap *current = _head;
	bool found = false;

	if (this->_name == target)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" tried to destroy itself!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" is disfunctional!" << std::endl;
		return ;
	}
	if (this->_energyPoints < this->_attackDamage)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" does not have enough energy to attack!" << std::endl;
		return ;
	}
	while (current)
	{
		if (current->_hitPoints == 0)
		{
			std::cout << "ClapTrap \"" << current->_name << "\" was already destroyed!" << std::endl;
			return;
		}
		if (current->_name == target)
		{
			found = true;
			if (this->_attackDamage > current->_hitPoints)
			{
				std::cout << "ClapTrap \"" << this->_name << "\" wasted " << this->_attackDamage - current->_hitPoints << " energy points!" << std::endl;
				current->_hitPoints = 0;
			}
			else
				current->_hitPoints -= this->_attackDamage;
			this->_energyPoints -= this->_attackDamage;
			std::cout << "ClapTrap \"" << this->_name << "\" attacks \"" << target << "\", causing " << this->_attackDamage << " points of damage!" << std::endl;
			if (current->_hitPoints == 0)
				std::cout << "ClapTrap \"" << target << "\" was destroyed!" << std::endl;
		}
		current = current->_next;
	}
	if (found == false)
		std::cout << "ClapTrap \"" << target << "\" does not exist!" << std::endl;
}

void ClapTrap::takeDamage(uInt amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap \"" << this->_name << "\" takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(uInt amount)
{
	this->_energyPoints -= amount;
	this->_hitPoints += amount;
	std::cout << "ClapTrap \"" << this->_name << "\" is being repaired, using " << amount << " energy points!" << std::endl;
}

void ClapTrap::printInfo()
{
	std::cout << std::endl << "  - " << this->_name <<
	std::endl << "  Hit points    (" << this->_hitPoints << ")" <<
	std::endl << "  Energy points (" << this->_energyPoints << ")" <<
	std::endl << "  Attack damage (" << this->_attackDamage << ")" << std::endl << std::endl;
}

void ClapTrap::setAttackDamage(uInt attackDamage)
{
	this->_attackDamage = attackDamage;
	std::cout << this->_name << ": Attack damage set to " << attackDamage << "!" << std::endl;
}

void ClapTrap::setEnergyPoints(uInt energyPoints)
{
	this->_energyPoints = energyPoints;
	std::cout << this->_name << ": Energy points set to " << energyPoints << "!" << std::endl;
}
