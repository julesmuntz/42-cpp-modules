#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Alan", 242);
		Form f("V", 7, 3);
		std::cout << f;
		std::cout << b;
		b.signForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Brian", 5);
		Form f("W", 4, 3);
		std::cout << f;
		std::cout << b;
		b.signForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Carl", 0);
		Form f("X", 1, 3);
		std::cout << f;
		std::cout << b;
		b.signForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("David", 149);
		Form f("Y", 149, 3);
		std::cout << f;
		std::cout << b;
		b.signForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl << "-------------------------------------------" << std::endl;
	{
		Bureaucrat b("Eric", -7);
		Form f("Z", 2, 3);
		std::cout << f;
		std::cout << b;
		b.signForm(&f);
		std::cout << f;
	}
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl << std::endl;
	return 0;
}
