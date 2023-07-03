#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <limits.h>

class Span
{
public:
	Span(unsigned N);
	Span(Span const &copy);
	~Span();
	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	std::vector<int> getVector();

private:
	Span();
	Span &operator=(Span const &rhs);
	std::vector<int> _vec;
	unsigned _N;
};
