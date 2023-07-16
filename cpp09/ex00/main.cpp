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

static size_t lenUntil(const std::string &str, char c)
{
	size_t pos = str.find(c);
	if (pos != std::string::npos)
		return pos;
	else
		return str.length();
}

static void parseDate(BitcoinExchange &be, const std::string &dateStr)
{
	if (dateStr.size() < 10)
	{
		throw BitcoinExchange::InvalidLineException();
	}
	int yearLen = lenUntil(dateStr, '-');
	be.date[YEAR] = atoi(dateStr.substr(0, yearLen).c_str());
	be.date[MONTH] = atoi(dateStr.substr((yearLen + 1), 2).c_str());
	be.date[DAY] = atoi(dateStr.substr((yearLen + 4), 2).c_str());
	if (be.date[YEAR] < 0 || be.date[MONTH] < 1 || be.date[MONTH] > 12 ||
		be.date[DAY] < 1 || be.date[DAY] > maxDayInMonth(be.date[MONTH], be.date[YEAR]))
	{
		throw BitcoinExchange::InvalidDateException();
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	std::map<std::string, BitcoinExchange> exchangeData;
	std::ifstream file(av[1]);
	if (file)
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::string dateStr = line.substr(0, line.find(','));
			float value = atof(line.substr(line.find(',') + 1).c_str());
			BitcoinExchange be;
			be.value = value;
			try
			{
				if (be.value < 0 || be.value > 1000)
					throw BitcoinExchange::InvalidValueException();
				parseDate(be, dateStr);
				std::cout << line << std::endl;
			}
			catch (BitcoinExchange::InvalidLineException &e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch (BitcoinExchange::InvalidDateException &e)
			{
				std::cerr << e.what() << std::endl;
			}
			catch (BitcoinExchange::InvalidValueException &e)
			{
				std::cerr << e.what() << std::endl;
			}
			exchangeData[dateStr] = be;
		}
		file.close();
	}
	else
		std::cerr << "Error: file not found" << std::endl;
	return 0;
}
