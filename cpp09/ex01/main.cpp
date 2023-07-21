#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "\033[0;31mError: wrong number of arguments.\033[0;0m" << std::endl;
		return 1;
	}
	RPN rpn;
	std::cout << rpn.calculator(av[1]) << std::endl;
	return 0;
}
