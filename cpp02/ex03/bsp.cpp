#include "Point.hpp"

static float space(Fixed aX, Fixed aY, Fixed bX, Fixed bY, Fixed cX, Fixed cY)
{
	return std::abs((aX.toFloat() * (bY.toFloat() - cY.toFloat()) + bX.toFloat() *
	 (cY.toFloat() - aY.toFloat()) + cX.toFloat() * (aY.toFloat() - bY.toFloat())) / 2.0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed aX = a.getX(); Fixed bX = b.getX(); Fixed cX = c.getX(); Fixed pX = point.getX();
	Fixed aY = a.getY(); Fixed bY = b.getY(); Fixed cY = c.getY(); Fixed pY = point.getY();

	float spaceABC = space(aX, aY, bX, bY, cX, cY);
	float spacePBC = space(pX, pY, bX, bY, cX, cY);
	float spacePAC = space(aX, aY, pX, pY, cX, cY);
	float spacePAB = space(aX, aY, bX, bY, pX, pY);

	if (spacePBC == 0 || spacePAC == 0 || spacePAB == 0)
		return false;
	return (spaceABC == spacePBC + spacePAC + spacePAB);
}

