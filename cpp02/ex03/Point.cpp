#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const a, float const b) : _x(a), _y(b)
{
}

Point::Point(Point const &copy)
{
	*this = copy;
}

Point	&Point::operator=(Point const &copy)
{
	const_cast<Fixed &>(_x) = copy._x;
	const_cast<Fixed &>(_y) = copy._y;
	return *this;
}

Point::~Point()
{
}

float Point::getX() const
{
	return _x.toFloat();
}

float Point::getY() const
{
	return _y.toFloat();
}
