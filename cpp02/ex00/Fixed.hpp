#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed &operator=(Fixed const &copy);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int 				_fixedPointValue;
		static int const	_fractionalBits = 8;
};

#endif