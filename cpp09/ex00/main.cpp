#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>

static bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static int maxDayInMonth(int month, int year)
{
	switch (month)
	{
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 31;
	}
}

static void checkDataBase(std::map<std::string, double> &dataBaseMap)
{
	std::ifstream file("data.csv");
	if (!file)
	{
		std::cerr << "\033[0;31mError: file \"data.csv\" not found.\033[0;0m" << std::endl;
		return;
	}
	int line = 0;
	try
	{
		bool firstLine = true;
		std::string lineStr;
		while (std::getline(file, lineStr))
		{
			line++;
			if (firstLine == true)
			{
				firstLine = false;
				continue;
			}
			std::string date = lineStr.substr(0, lineStr.find(','));
			double value = strtod(lineStr.substr(lineStr.find(',') + 1).c_str(), NULL);
			if (date.size() < 10)
				throw std::exception();
			size_t firstDash = date.find('-');
			size_t secondDash = date.find('-', firstDash + 1);
			if (firstDash == std::string::npos || secondDash == std::string::npos)
				throw std::exception();
			short year = atoi(date.substr(0, firstDash).c_str());
			short month = atoi(date.substr(firstDash + 1, secondDash - firstDash - 1).c_str());
			short day = atoi(date.substr(secondDash + 1).c_str());
			if (year < 0 || month < 1 || month > 12 ||
				day < 1 || day > maxDayInMonth(month, year))
				throw std::exception();
			dataBaseMap[date] = value;
		}
		file.close();
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[0;31mError: invalid database content (line " << line << ")\033[0;0m" << std::endl;
	}
	return;
}

static double getExchangeRate(std::string date, double value, std::map<std::string, double> &dataBaseMap)
{
	double result;
	std::map<std::string, double>::iterator it = dataBaseMap.upper_bound(date);
	if (it != dataBaseMap.begin())
	{
		--it;
		result = value * it->second;
	}
	else
		result = 0;
	return result;
}

static void checkInput(std::map<std::string, double> &dataBaseMap, int ac, char *arg)
{
	std::ifstream file(arg);
	if (!file || ac != 2)
	{
		std::cerr << "\033[0;31mError: could not open file.\033[0;0m" << std::endl;
		return;
	}
	bool firstLine = true;
	std::string lineStr;
	while (std::getline(file, lineStr))
	{
		if (firstLine == true)
		{
			firstLine = false;
			continue;
		}
		std::string date = lineStr.substr(0, lineStr.find('|') - 1);
		double value = strtod(lineStr.substr(lineStr.find('|') + 2).c_str(), NULL);
		try
		{
			if (value < 0)
				throw BitcoinExchange::NegativeValueException();
			if (value > 1000)
				throw BitcoinExchange::TooLargeValueException();
			if (date.size() < 10)
				throw BitcoinExchange::InvalidSyntaxException();
			size_t firstDash = date.find('-');
			size_t secondDash = date.find('-', firstDash + 1);
			if (firstDash == std::string::npos || secondDash == std::string::npos)
				std::cerr << "\033[0;31mError: bad input => " << date << "\033[0m" << std::endl;
			short year = atoi(date.substr(0, firstDash).c_str());
			short month = atoi(date.substr(firstDash + 1, secondDash - firstDash - 1).c_str());
			short day = atoi(date.substr(secondDash + 1).c_str());
			if (year < 0 || month < 1 || month > 12 ||
				day < 1 || day > maxDayInMonth(month, year))
				std::cerr << "\033[0;31mError: bad input => " << date << "\033[0m" << std::endl;
			else
				std::cout << date << " => " << value << " = " << getExchangeRate(date, value, dataBaseMap) << std::endl;
		}
		catch (BitcoinExchange::NegativeValueException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (BitcoinExchange::TooLargeValueException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (BitcoinExchange::InvalidSyntaxException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
	return;
}

int main(int ac, char **av)
{
	std::map<std::string, double> dataBaseMap;
	checkDataBase(dataBaseMap);
	checkInput(dataBaseMap, ac, av[1]);
	return 0;
}
