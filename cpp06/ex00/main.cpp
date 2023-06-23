#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		std::cout << argv[0] << " " << argv[1] << std::endl;
		ScalarConverter::convert(argv[1]);
	}
	else
	{
		std::cout << std::endl << "Works with the following arguments:" << std::endl << std::endl << "\t\"./convert\" \"<value>\"" << std::endl << std::endl;
	}
	return 0;
}
