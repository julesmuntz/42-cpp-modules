#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <csignal>
#include <sstream>

int ft_stoi(std::string str)
{
	int res;
	std::stringstream ss;
	ss << str;
	ss >> res;
	return res;
}

int str_is(int (*function_is)(int), std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!function_is(str[i]))
			return 0;
		i++;
	}
	return 1;
}

void get_contact(PhoneBook &data, std::string &field)
{
	if (data.contact_index == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl << std::endl;
		return;
	}
	std::string input;
	while (true)
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			return;
		}
		else if (!input.empty() && str_is(&std::isdigit, input) && ft_stoi(input) >= 1 &&
				((data.array_is_full == true && ft_stoi(input) <= 8) ||
				(data.array_is_full == false && ft_stoi(input) <= data.contact_index)))
		{
			field = input;
			break;
		}
		else if (input.empty())
			std::cerr << "Field is empty, try again." << std::endl;
		else
			std::cerr << "Invalid input, try again." << std::endl;
	}
	std::cout <<
	std::endl << "\tFirst name:\t" << data.contact[ft_stoi(input)-1].Contact::get_first_name() <<
	std::endl << "\tLast name:\t" << data.contact[ft_stoi(input)-1].Contact::get_last_name() <<
	std::endl << "\tNickname:\t" << data.contact[ft_stoi(input)-1].Contact::get_nickname() <<
	std::endl << "\tPhone number:\t" << data.contact[ft_stoi(input)-1].Contact::get_phone_number() <<
	std::endl << "\tDarkest secret:\t" << data.contact[ft_stoi(input)-1].Contact::get_darkest_secret() << std::endl << std::endl;
}

void get_input(const std::string &message, std::string &field, int (*function_is)(int))
{
	std::string input;
	while (true)
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			return;
		}
		else if (!input.empty() && str_is(function_is, input))
		{
			field = input;
			break;
		}
		else if (input.empty())
			std::cerr << "Field is empty, try again." << std::endl;
		else
			std::cerr << "Invalid input, try again." << std::endl;
	}
}

void add_contact(PhoneBook &data)
{
	if (data.contact_index == 8)
	{
		data.contact_index = 0;
		data.array_is_full = true;
	}
	std::cout << std::endl << "- Contact " << (int)(data.contact_index + 1) << " -" << std::endl;
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	get_input("Enter first name: ", first_name, &std::isalnum);
	get_input("Enter last name: ", last_name, &std::isalnum);
	get_input("Enter nickname: ", nickname, &std::isalnum);
	get_input("Enter phone number: ", phone_number, &std::isdigit);
	get_input("Enter darkest secret: ", darkest_secret, &std::isalnum);
	data.contact[data.contact_index].set_first_name(first_name);
	data.contact[data.contact_index].set_last_name(last_name);
	data.contact[data.contact_index].set_nickname(nickname);
	data.contact[data.contact_index].set_phone_number(phone_number);
	data.contact[data.contact_index].set_darkest_secret(darkest_secret);
	data.contact_index++;
	std::cout << std::endl;
}

std::string format_input(const std::string &input)
{
	std::string output(10, ' ');
	size_t input_length = input.length();

	if (input_length <= 10)
		output.replace(0, input_length, input);
	else
	{
		output.replace(0, 9, input, 0, 9);
		output[9] = '.';
	}
	return output;
}

int main(int ac, char **av)
{
	(void)av;
	if (ac < 1)
		return 0;
	int i = 0;
	PhoneBook data;
	data.contact_index = 0;
	data.array_is_full = false;
	std::string input;
	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT:" << std::endl << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
		else if (input == "ADD")
			add_contact(data);
		else if (input == "SEARCH")
		{
			i = 0;
			std::cout << std::endl << " index  first name   last name     nickname"
			<< std::endl << "----------------------------------------------" << std::endl;
			while (i < 8)
			{
				std::cout << "|  " << (int)(i+1) << "  | " <<
				format_input(data.contact[i].get_first_name()) << " | " <<
				format_input(data.contact[i].get_last_name()) << " | " <<
				format_input(data.contact[i].get_nickname()) << " |" << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
				i++;
			}
			get_contact(data, input);
		}
	}
	return 0;
}
