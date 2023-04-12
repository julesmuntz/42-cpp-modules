#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(""), ScavTrap(""), FragTrap("")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_className = "DiamondTrap";
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_name = name.erase((name.length()), 11);
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_className = "DiamondTrap";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << std::endl << "Who am I?" <<
	std::endl << std::endl << "DiamondTrap name:             " << _name <<
				 std::endl << "DiamondTrap ClapTrap name:    " << ClapTrap::getName() << std::endl << std::endl;
}
