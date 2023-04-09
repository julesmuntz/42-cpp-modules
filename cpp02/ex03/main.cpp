#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	Point p1(10, 15); // Point is inside the triangle.
	Point p2(20, 15); // Point is outside the triangle.
	Point p3(10, 30); // Point is on the edge of the triangle (outside).
	if (bsp(a, b, c, p1))
		std::cout << "Point is inside." << std::endl;
	else
		std::cout << "Point is outside." << std::endl;
	return 0;
}
