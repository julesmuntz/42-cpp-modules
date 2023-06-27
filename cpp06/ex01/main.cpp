#include "Serializer.hpp"

int main()
{
	Data *a = new Data();
	a->n = 42;
	a->s = "FT";

	std::cout << std::endl;

	std::cout << "- Data A -" << std::endl;
	std::cout << "int address:    " << &a->n << std::endl << "int value:      " << a->n << std::endl;
	std::cout << "string address: " << &a->s << std::endl << "string value:   " << a->s << std::endl;

	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(a);
	Data *b = Serializer::deserialize(raw);

	std::cout << "- Data B -" << std::endl;
	std::cout << "int address:    " << &b->n << std::endl << "int value:      " << b->n << std::endl;
	std::cout << "string address: " << &b->s << std::endl << "string value:   " << b->s << std::endl;

	std::cout << std::endl;

	delete a;
	return 0;
}
