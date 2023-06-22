#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
public:
	static void convert(std::string input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};
