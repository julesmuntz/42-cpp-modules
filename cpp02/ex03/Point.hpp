#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
					Point();
					Point(float const a, float const b);
					Point(Point const &copy);
		Point		&operator=(Point const &copy);
					~Point();
		float		getX() const;
		float		getY() const;

	private:
		Fixed const _x;
		Fixed const _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
