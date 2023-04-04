#include "Zombie.hpp"

int main(void)
{
	Zombie *horde1;
	Zombie *horde2;
	horde1 = zombieHorde(4, "Horde of 4");
	std::cout << std::endl;
	horde2 = zombieHorde(7, "Horde of 7");
	return (0);
}
