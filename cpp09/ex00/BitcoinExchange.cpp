#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this != &copy)
	{
		this->value = copy.value;
		this->date[YEAR] = copy.date[YEAR];
		this->date[MONTH] = copy.date[MONTH];
		this->date[DAY] = copy.date[DAY];
	}
	return (*this);
}
