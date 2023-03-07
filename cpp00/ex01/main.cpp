#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <csignal>

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

void get_input(const std::string &message, std::string &field, int (*function_is)(int))
{
	int invalid = 1;
	std::string input;
	while (invalid)
	{
		std::cout << message;
		std::getline(std::cin, input);
		if (str_is(function_is, input))
		{
			field = input;
			break;
		}
		std::cerr << "Try again." << std::endl;
	}
}

void add_contact(PhoneBook &data)
{
	if (data.contact_index == 8)
		data.contact_index = 0;
	std::cout << std::endl << "- Contact " << (int)(data.contact_index + 1) << " -" << std::endl;
	get_input("Enter first name: ", data.contact[data.contact_index].first_name, &std::isalnum);
	get_input("Enter last name: ", data.contact[data.contact_index].last_name, &std::isalnum);
	get_input("Enter nickname: ", data.contact[data.contact_index].nickname, &std::isalnum);
	get_input("Enter phone number: ", data.contact[data.contact_index].phone_number, &std::isdigit);
	get_input("Enter darkest secret: ", data.contact[data.contact_index].darkest_secret, &std::isalnum);
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
	std::string command;
	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT:" << std::endl << "> ";
		std::getline(std::cin, command);
		if (std::cin.eof() || command == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			break;
		}
		else if (command == "ADD")
			add_contact(data);
		else if (command == "SEARCH")
		{
			i = 0;
			std::cout << std::endl << " index  first name   last name     nickname"
			<< std::endl << "----------------------------------------------" << std::endl;
			while (i < 8)
			{
				std::cout << "|  " << (int)(i+1) << "  | " <<
				format_input(data.contact[i].first_name) << " | " <<
				format_input(data.contact[i].last_name) << " | " <<
				format_input(data.contact[i].nickname) << " |" << std::endl;
				std::cout << "----------------------------------------------" << std::endl;
				i++;
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
