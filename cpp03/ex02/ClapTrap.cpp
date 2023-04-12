#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0), _next(NULL)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

ClapTrap *ClapTrap::_head = NULL;

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _next(NULL)
{
	_className = "ClapTrap";
	std::cout << "ClapTrap constructor called" << std::endl;
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
	std::cout << "ClapTrap destructor called" << std::endl;
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
		std::cout << _className << " \"" << this->_name << "\" tried to destroy itself!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << _className << " \"" << this->_name << "\" is disfunctional!" << std::endl;
		return ;
	}
	if (this->_energyPoints < this->_attackDamage)
	{
		std::cout << _className << " \"" << this->_name << "\" does not have enough energy to attack!" << std::endl;
		return ;
	}
	while (current)
	{
		if (current->_name == target)
		{
			found = true;
			if (current->_hitPoints == 0)
			{
				std::cout << _className << " \"" << this->_name << "\" attacks " << current->_className << " \"" << target << "\", but it\'s already destroyed!" << std::endl;
				return;
			}
			if (this->_attackDamage > current->_hitPoints)
			{
				std::cout << _className << " \"" << this->_name << "\" wasted " << this->_attackDamage - current->_hitPoints << " energy points!" << std::endl;
				current->_hitPoints = 0;
			}
			else
				current->_hitPoints -= this->_attackDamage;
			this->_energyPoints -= this->_attackDamage;
			std::cout << _className << " \"" << this->_name << "\" attacks " << current->_className << " \"" << target << "\", causing " << this->_attackDamage << " points of damage!" << std::endl;
			if (current->_hitPoints == 0)
				std::cout << current->_className << " \"" << target << "\" was destroyed!" << std::endl;
		}
		current = current->_next;
	}
	if (found == false)
		std::cout << "Target \"" << target << "\" does not exist!" << std::endl;
}

void ClapTrap::takeDamage(uInt amount)
{
	this->_hitPoints -= amount;
	std::cout << _className << " \"" << this->_name << "\" takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(uInt amount)
{
	this->_energyPoints -= amount;
	this->_hitPoints += amount;
	std::cout << _className << " \"" << this->_name << "\" is being repaired, using " << amount << " energy points!" << std::endl;
}

void ClapTrap::printInfo()
{
	std::cout << std::endl << "  - " << _className << " " << this->_name <<
	std::endl << "  Hit points    (" << this->_hitPoints << ")" <<
	std::endl << "  Energy points (" << this->_energyPoints << ")" <<
	std::endl << "  Attack damage (" << this->_attackDamage << ")" << std::endl << std::endl;
}

void ClapTrap::setAttackDamage(uInt attackDamage)
{
	this->_attackDamage = attackDamage;
	std::cout << _className << " " << this->_name << ": Attack damage set to " << attackDamage << "!" << std::endl;
}

void ClapTrap::setEnergyPoints(uInt energyPoints)
{
	this->_energyPoints = energyPoints;
	std::cout << _className << " " << this->_name << ": Energy points set to " << energyPoints << "!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

uInt ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

uInt ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

uInt ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}
