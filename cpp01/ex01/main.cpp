#include "Zombie.hpp"

int main(void)
{
	Zombie *horde1;
	Zombie *horde2;

	std::cout << std::endl << "(Horde 1)" << std::endl;
	horde1 = zombieHorde(4, "One");

	std::cout << std::endl << "(Horde 2)" << std::endl;
	horde2 = zombieHorde(7, "Two");

	std::cout << std::endl << "(Horde 1)" << std::endl;
	delete[] horde1;

	std::cout << std::endl << "(Horde 2)" << std::endl;
	delete[] horde2;
	std::cout << std::endl;

	return (0);
}
