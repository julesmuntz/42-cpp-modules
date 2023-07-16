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

	float value;
	short date[3];

	class InvalidLineException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: invalid line syntax.\033[0m";
		}
	};
	class InvalidDateException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: invalid date. (Gregorian calendar)\033[0m";
		}
	};
	class InvalidValueException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "\033[0;31mError: invalid value. (range 0-1000)\033[0m";
		}
	};
};
