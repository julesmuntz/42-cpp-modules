#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact	contact[8];
		int		contact_index;
		bool	array_is_full;
};

#endif