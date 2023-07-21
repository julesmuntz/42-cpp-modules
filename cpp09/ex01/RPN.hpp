#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(RPN const &copy);
	RPN &operator=(RPN const &copy);
	double calculator(std::string operation);
};
