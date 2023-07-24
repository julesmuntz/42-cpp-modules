#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "\033[0;31mError: wrong number of arguments.\033[0;0m" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.printResult(av[1]);
	return 0;
}
