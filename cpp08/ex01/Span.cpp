#include "Span.hpp"

Span::Span()
{
	// std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned N) : _N(N)
{
	try
	{
		_vec.reserve(N);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// std::cout << "Span parameter constructor called" << std::endl;
}

Span::~Span()
{
	// std::cout << "Span destructor called" << std::endl;
}

Span::Span(Span const &copy)
{
	*this = copy;
	// std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
		_N = rhs._N;
	// std::cout << "Span assignation operator called" << std::endl;
	return *this;
}

void Span::addNumber(int number)
{
	this->_vec.push_back(number);
}

int Span::shortestSpan()
{
	int span = INT_MAX;
	std::vector<int> temp = this->_vec;
	std::sort(temp.begin(), temp.end());
	for (unsigned i = 0; i < temp.size() - 1; ++i)
		if ((temp[i + 1] - temp[i]) < span)
			span = (temp[i + 1] - temp[i]);
	return span;
}

int Span::longestSpan()
{
	std::vector<int>::iterator min = std::min_element(this->_vec.begin(), this->_vec.end());
	std::vector<int>::iterator max = std::max_element(this->_vec.begin(), this->_vec.end());
	return *max - *min;
}

std::vector<int> Span::getVector()
{
	return this->_vec;
}
