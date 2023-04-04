#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;
	std::cout << std::endl;

	zombie1 = newZombie("One");
	zombie1->announce();
	delete zombie1;
	std::cout << std::endl;

	zombie1 = newZombie("One");
	zombie1->announce();
	delete zombie1;
	std::cout << std::endl;

	zombie2 = newZombie("Two");
	zombie2->announce();
	delete zombie2;
	std::cout << std::endl;

	randomChump("Three");
	std::cout << std::endl;
	return (0);
}
