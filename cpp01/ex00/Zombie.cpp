#include "Zombie.hpp"

Zombie::Zombie(std::string n) : name(n)
{
	std::cout << "Zombie \"" << name << "\" built." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << name << "\" destroyed." << std::endl;
}

void Zombie::announce(void)
{
	if (this->name != "")
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << "<name>: BraiiiiiiinnnzzzZ..." << std::endl;
}
