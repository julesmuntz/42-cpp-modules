#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
public:
	static void convert(std::string input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	static std::string getChar(std::string input);
	static std::string getInt(std::string input);
	static std::string getFloat(std::string input);
	static std::string getDouble(std::string input);
};
