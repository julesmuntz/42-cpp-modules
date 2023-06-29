#pragma once

#include <iostream>
#include <string>

template<typename A, typename B, typename C>
void iter(A *arrayPtr, B arrayLen, C (*function)(A &))
{
	for (B i = 0; i < arrayLen; i++)
		function(arrayPtr[i]);
}
