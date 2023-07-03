#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(42);
	vec.push_back(5);
	easyfind(vec, 42);
	easyfind(vec, 23);
	return 0;
}
