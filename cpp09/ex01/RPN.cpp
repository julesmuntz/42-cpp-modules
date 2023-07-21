#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN &RPN::operator=(RPN const &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

double RPN::calculator(std::string operation)
{
	try
	{
		std::istringstream iss(operation);
		std::stack<double> stk;
		std::string token;
		int operands = 0;
		while (iss >> token)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				if (stk.size() < 2)
					throw std::exception();
				double a = stk.top();
				stk.pop();
				double b = stk.top();
				stk.pop();
				if (token == "+")
					stk.push(a + b);
				else if (token == "-")
					stk.push(b - a);
				else if (token == "*")
					stk.push(a * b);
				else if (token == "/")
				{
					if (a == 0)
						throw std::exception();
					stk.push(b / a);
				}
			}
			else
			{
				char *end;
				double value = std::strtod(token.c_str(), &end);
				if (end == token.c_str() || *end != '\0')
					throw std::exception();
				stk.push(value);
				operands++;
				if (operands > 10)
					throw std::exception();
			}
		}
		if (stk.size() > 1)
			throw std::exception();
		return stk.top();
	}
	catch (std::exception &e)
	{
		std::cout << "\033[0;31mError: invalid expression.\033[0;0m" << std::endl;
		exit(EXIT_FAILURE);
	}
}
