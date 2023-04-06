#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		return std::cout << "Enter DEBUG, INFO, WARNING or ERROR." << std::endl, 0;
	Harl hal;
	hal.complain(av[1]);
	return 0;
}
