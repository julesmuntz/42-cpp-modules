#include "easyfind.hpp"

template <typename T>
int easyfind(T a, int b)
{
	typename T::iterator it = find(a.begin(), a.end(), b);
	if (it == a.end())
	{
		std::cerr << "\033[0;31mElement \"" << b << "\" not found!\033[0;0m" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "\033[0;32mElement \"" << b << "\" found!\033[0;0m" << std::endl;
		return 0;
	}

}
