#pragma once

#include <iostream>
#include <string>

template <class T>
class Array
{
public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(Array const &copy);
	Array &operator=(Array const &rhs);
	unsigned int size();

private:
	T *_array;
	unsigned int _size;
};

#include "Array.tpp"
