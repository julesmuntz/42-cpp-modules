#include "iter.hpp"

void testFunction(int &var)
{
	var++;
	std::cout << var << " ";
}

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	iter<int>(array, 5, testFunction);
	std::cout << std::endl;
}
