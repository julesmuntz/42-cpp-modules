#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <limits.h>
#include <ctime>

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
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class ContainerFullException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: container is full\033[0m";
		}
	};

	class ContainerEmptyException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: container is empty\033[0m";
		}
	};

	class LessThanTwoException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: container has less than two elements\033[0m";
		}
	};

private:
	Span();
	Span &operator=(Span const &rhs);
	std::vector<int> _vec;
	unsigned _N;
};
