#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <map>

#define YEAR 0
#define MONTH 1
#define DAY 2

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(BitcoinExchange const &copy);

	double value;
	short date[3];

	class NegativeValueException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: not a positive number.\033[0m";
		}
	};
	class TooLargeValueException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: too large a number.\033[0m";
		}
	};
};
