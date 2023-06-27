#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdint.h>

typedef struct Data
{
	int n;
	std::string s;
} Data;

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
};
