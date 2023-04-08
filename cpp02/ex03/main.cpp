#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point point(0, 1);
	if (bsp(a, b, c, point))
		std::cout << "Point is inside." << std::endl;
	else
		std::cout << "Point is outside." << std::endl;
	return 0;
}
