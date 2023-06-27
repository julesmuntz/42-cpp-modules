#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *base;
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			base = new A;
			break;
		case 1:
			base = new B;
			break;
		case 2:
			base = new C;
			break;
	}
	return base;
}

void identify(Base *p)
{
	Base *base = dynamic_cast<Base *>(p);
	if (!base)
		std::cout << "Instance unidentified." << std::endl;
	else if (dynamic_cast<A *>(base))
		std::cout << "Instance \'A\' identified." << std::endl;
	else if (dynamic_cast<B *>(base))
		std::cout << "Instance \'B\' identified." << std::endl;
	else if (dynamic_cast<C *>(base))
		std::cout << "Instance \'C\' identified." << std::endl;
}

void identify(Base &p)
{
	try
	{
		Base &base = dynamic_cast<Base &>(p);
		if (dynamic_cast<A *>(&base))
			std::cout << "Instance \'A\' identified." << std::endl;
		else if (dynamic_cast<B *>(&base))
			std::cout << "Instance \'B\' identified." << std::endl;
		else if (dynamic_cast<C *>(&base))
			std::cout << "Instance \'C\' identified." << std::endl;
		else
			throw std::exception();
	}
	catch (std::exception &e)
	{
		std::cout << "Instance unidentified." << std::endl;
	}
}

int main()
{
	std::cout << std::endl;
	{
		std::cout << "- Generated instance -" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	std::cout << std::endl;
	{
		std::cout << "- Null instance -" << std::endl;
		Base *base = NULL;
		identify(base);
		identify(*base);
		delete base;
	}
	std::cout << std::endl;
	return 0;
}
