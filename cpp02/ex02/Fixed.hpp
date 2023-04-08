#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
					Fixed();
					Fixed(Fixed const &copy);
		Fixed		&operator=(Fixed const &copy);
					~Fixed();

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
					Fixed(int const value);
					Fixed(float const value);
		float		toFloat(void) const;
		int			toInt(void) const;

		bool		operator>(Fixed const &other) const;
		bool		operator<(Fixed const &other) const;
		bool		operator>=(Fixed const &other) const;
		bool		operator<=(Fixed const &other) const;
		bool		operator==(Fixed const &other) const;
		bool		operator!=(Fixed const &other) const;
		Fixed		operator+(Fixed const &other) const;
		Fixed		operator-(Fixed const &other) const;
		Fixed		operator*(Fixed const &other) const;
		Fixed		operator/(Fixed const &other) const;
		Fixed		operator++(int);
		Fixed		&operator++();
		Fixed		operator--(int);
		Fixed		&operator--();
static	Fixed		min(Fixed &a, Fixed &b);
static	Fixed const	min(Fixed const &a, Fixed const &b);
static	Fixed		max(Fixed &a, Fixed &b);
static	Fixed const	max(Fixed const &a, Fixed const &b);

	private:
		int 				_fixedPointValue;
		static int const	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
