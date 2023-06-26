#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
public:
	static void convert(std::string input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	static void printChar(std::string input);
	static void printInt(std::string input);
	static void printFloat(std::string input);
	static void printDouble(std::string input);
};
