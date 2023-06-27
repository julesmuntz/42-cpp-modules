#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Base
{
public:
	virtual ~Base();
};

std::ostream &operator<<(std::ostream &out, Base const &other);
