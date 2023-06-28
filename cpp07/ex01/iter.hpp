#pragma once

#include <iostream>
#include <string>

template<typename T>
void iter(T *arrayAddress, int arrayLen, void (*function)(T &))
{
	for (int i = 0; i < arrayLen; i++)
		function(arrayAddress[i]);
}
