#pragma once

#include <iostream>
#include <iterator>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end();
	}
	const_iterator begin() const
	{
		return std::stack<T>::c.begin();
	}
	const_iterator end() const
	{
		return std::stack<T>::c.end();
	}

	void pop()
	{
		std::cout << "Value \"" << std::stack<T>::top() << "\" deleted." << std::endl;
		std::stack<T>::pop();
	}
	void push(const T &value)
	{
		std::cout << "Value \"" << value << "\" pushed." << std::endl;
		std::stack<T>::push(value);
	}
	void push_back(const T &value)
	{
		std::cout << "Value \"" << value << "\" pushed." << std::endl;
		std::stack<T>::push(value);
	}

	MutantStack()
	{
	}
	~MutantStack()
	{
	}
	MutantStack(MutantStack const &copy) : std::stack<T>(copy)
	{
	}
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}
};
