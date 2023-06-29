#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template <class T>
class Array
{
public:
	Array();
	~Array();
	Array(unsigned n);
	Array(Array const &copy);
	Array &operator=(Array const &rhs);
	T &operator[](unsigned index);
	unsigned size();
	void setArray(T *array);

private:
	T *_array;
	unsigned _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &rhs);

#include "Array.tpp"
