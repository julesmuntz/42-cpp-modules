#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0)
{
	_array = new T[_size];
	// std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
	// std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned n) : _size(n)
{
	_array = new T[_size];
	// std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &copy)
{
	*this = copy;
	// std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
unsigned Array<T>::size()
{
	return _size;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	_size = rhs._size();
	_array = new T[_size];
	for (unsigned i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	// std::cout << "Array assignment operator called" << std::endl;
	return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &rhs)
{
	if (rhs.size() == 0)
	{
		o << "\033[0;35mArray is empty!\033[0;0m";
		return o;
	}
	for (unsigned i = 0; i < rhs.size(); i++)
		o << "[" << rhs[i] << "] ";
	return o;
}

template <typename T>
T &Array<T>::operator[](unsigned index)
{
	if (index >= this->_size)
		throw std::exception();
	return this->_array[index];
}

template <typename T>
void Array<T>::setArray(T *array)
{
	for (unsigned i = 0; i < _size; i++)
		_array[i] = array[i];
}
