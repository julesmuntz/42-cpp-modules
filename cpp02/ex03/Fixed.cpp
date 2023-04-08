#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

bool Fixed::operator>(Fixed const &other) const
{
	return (this->_fixedPointValue > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->_fixedPointValue < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->_fixedPointValue >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->_fixedPointValue <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->_fixedPointValue == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->_fixedPointValue != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(Fixed const &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(Fixed const &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(Fixed const &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return (tmp);
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixedPointValue <= b._fixedPointValue)
		return a;
	else
		return b;
}

Fixed const Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._fixedPointValue <= b._fixedPointValue)
		return a;
	else
		return b;
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixedPointValue >= b._fixedPointValue)
		return a;
	else
		return b;
}

Fixed const Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._fixedPointValue >= b._fixedPointValue)
		return a;
	else
		return b;
}
