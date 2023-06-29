#include "iter.hpp"

std::string incrementDigit(int &n)
{
	n++;
	return "Test";
}

int main()
{
	int array[5] = {13452, 5432, 363, 42, 4563230};
	std::cout << std::endl << "Array before incrementDigit():" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl << std::endl << "Array after incrementDigit():" << std::endl;
	iter<int>(array, 5, incrementDigit);
	for (int i = 0; i < 5; i++)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl << std::endl;
}
