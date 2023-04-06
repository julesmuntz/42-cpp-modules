#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl hal;
	hal.complain("DEBUG");
	std::cout << std::endl;
	hal.complain("INFO");
	std::cout << std::endl;
	hal.complain("WARNING");
	std::cout << std::endl;
	hal.complain("ERROR");
	std::cout << std::endl;
}
