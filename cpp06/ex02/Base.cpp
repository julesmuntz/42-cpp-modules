#include "Base.hpp"

Base::~Base()
{
}

std::ostream &operator<<(std::ostream &out, Base const &other)
{
	(void)other;
	return out;
}
