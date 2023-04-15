#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *arr[10];
	std::cout << "[ CONSTRUCTOR CALLS ]" << std::endl << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "- Object " << i+1 << " -" << std::endl;
		if (i % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl << "[ DESTRUCTOR CALLS ]" << std::endl << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "- Object " << i+1 << " -" << std::endl;
		delete arr[i];
		std::cout << std::endl;
	}
	return 0;
}
