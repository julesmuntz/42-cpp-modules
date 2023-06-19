#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << std::endl
			  << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Alan", 242);
		AForm f("V", 7, 3);
		std::cout << f;
		std::cout << b;
		b.signAForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Brian", 5);
		AForm f("W", 4, 3);
		std::cout << f;
		std::cout << b;
		b.signAForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Carl", 0);
		AForm f("X", 1, 3);
		std::cout << f;
		std::cout << b;
		b.signAForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("David", 149);
		AForm f("Y", 149, 3);
		std::cout << f;
		std::cout << b;
		b.signAForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Eric", -7);
		AForm f("Z", 2, 3);
		std::cout << f;
		std::cout << b;
		b.signAForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl
			  << std::endl;
	return 0;
}
