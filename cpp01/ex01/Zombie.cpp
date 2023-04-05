#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie constructor called." << std::endl;
}

Zombie::Zombie(std::string n) : name(n)
{
	std::cout << "Zombie constructor called." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie constructor destroyed." << std::endl;
}

void Zombie::announce(void)
{
	if (this->name != "")
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << "<name>: BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}