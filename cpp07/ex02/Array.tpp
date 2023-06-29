#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	_array = new T[_size];
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
	std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned n) : _size(n)
{
	_array = new T[_size];
	std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &copy)
{
	std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	std::cout << "Array assignment operator called" << std::endl;
	return *this;
}

template <typename T>
unsigned Array<T>::size()
{
	unsigned i = 0;
	while (this->_array[i])
		i++;
	return i;
}
