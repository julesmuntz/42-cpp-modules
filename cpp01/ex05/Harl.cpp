#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

using std::cout;
using std::endl;

void	Harl::debug()
{
	cout << "DEBUG:" << endl <<
"\t\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\"" << endl;
}

void	Harl::info()
{
	cout << "INFO:" << endl <<
"\t\"I cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\"" << endl;
}

void	Harl::warning()
{
	cout << "WARNING:" << endl <<
"\t\"I think I deserve to have some extra bacon for free. \
I've been coming for years whereas you started working here since last month.\"" << endl;
}

void	Harl::error()
{
	cout << "ERROR:" << endl <<
"\t\"This is unacceptable! I want to speak to the manager now.\"" << endl;
}

void	Harl::complain(std::string level)
{
	void(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4;i++)
		if (levels[i] == level)
			(this->*f[i])();
}
