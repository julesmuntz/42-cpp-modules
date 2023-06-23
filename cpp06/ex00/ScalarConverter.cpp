#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter assignation operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

std::string ScalarConverter::getChar(std::string input)
{
	std::istringstream iss(input);
	int ascii_value;
	iss >> ascii_value;
	char c = static_cast<char>(ascii_value);
	if (input.length() == 1 && isascii(input[0]) && !isdigit(input[0]))
		return "\'" + input + "\'";
	else if (ascii_value >= 32 && ascii_value <= 126)
		return "\'" + std::string(1, c) + "\'";
	else if (ascii_value < 0 || ascii_value > 127)
		return "impossible";
	else
		return "Non displayable";
}

std::string ScalarConverter::getInt(std::string input)
{
	std::istringstream iss(input);
	int value;
	if (!(iss >> value))
		return ("impossible");
	int i = 0;
	std::string output;
	bool dot_found = false;
	while (input[i])
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
		{
			if (input[i] == '-')
				output += input[i];
			i++;
		}
		if (dot_found == false)
			output += input[i];
		if (dot_found == false && (input[i] == '.'))
		{
			dot_found = true;
			i++;
		}
		if (dot_found == true && (i == static_cast<int>(input.length()-1) && input[i] == 'f'))
			i++;
		if (!isdigit(input[i]))
			break;
		i++;
	}
	if (input[i])
		return ("impossible");
	if (output.end()[-1] == '.')
		output.erase(output.length()-1);
	return (output);
}

std::string ScalarConverter::getFloat(std::string input)
{
	std::istringstream iss(input);
	float value;
	if (!(iss >> value))
		return ("impossible");
	int i = 0;
	std::string output;
	bool dot_found = false;
	int dot_pos = 0;
	while (input[i])
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
		{
			if (input[i] == '-')
				output += input[i];
			i++;
		}
		output += input[i];
		if (dot_found == false && (input[i] == '.'))
		{
			dot_found = true;
			dot_pos = i;
			i++;
			output += input[i];
		}
		if (dot_found == true && (i == static_cast<int>(input.length()-1) && input[i] == 'f'))
			i++;
		if (!isdigit(input[i]))
			break;
		i++;
	}
	if (input[i])
		return ("impossible");
	for (i = static_cast<int>(output.length()-1); !(output[i] >= '1' && output[i] <= '9'); i--)
		output.erase(i, 1);
	if (input.end()[-1] == '.')
		return output = input + "0f";
	if (dot_found == false || i == dot_pos-1)
		return output + ".0f";
	return (output + "f");
}

std::string ScalarConverter::getDouble(std::string input)
{
	std::istringstream iss(input);
	double value;
	if (!(iss >> value))
		return ("impossible");
	int i = 0;
	std::string output;
	bool dot_found = false;
	int dot_pos = 0;
	while (input[i])
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
		{
			if (input[i] == '-')
				output += input[i];
			i++;
		}
		output += input[i];
		if (dot_found == false && (input[i] == '.'))
		{
			dot_found = true;
			dot_pos = i;
			i++;
			output += input[i];
		}
		if (dot_found == true && (i == static_cast<int>(input.length()-1) && input[i] == 'f'))
			i++;
		if (!isdigit(input[i]))
			break;
		i++;
	}
	if (input[i])
		return ("impossible");
	for (i = static_cast<int>(output.length()-1); !(output[i] >= '1' && output[i] <= '9'); i--)
		output.erase(i, 1);
	if (input.end()[-1] == '.')
		return output = input + "0";
	if (dot_found == false || i == dot_pos-1)
		return output + ".0";
	return (output);
}

void ScalarConverter::convert(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "nan" || input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl;
		if (input[0] == '-' || input[0] == '+')
			std::cout << "float: " << input[0] << "inff" << std::endl << "double: " << input[0] << "inf" << std::endl;
		else
			std::cout << "float: " << "nanf" << std::endl << "double: " << "nan" << std::endl;
		return;
	}
	std::cout << "char:   " << ScalarConverter::getChar(input) << std::endl;
	std::cout << "int:    " << ScalarConverter::getInt(input) << std::endl;
	std::cout << "float:  " << ScalarConverter::getFloat(input) << std::endl;
	std::cout << "double: " << ScalarConverter::getDouble(input) << std::endl;
}
