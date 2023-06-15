#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl;
	{
		Bureaucrat b("Alan", 242);
		std::cout << b;
	}
	std::cout << std::endl;
	{
		Bureaucrat b("Brian", 5);
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		std::cout << b;
	}
	std::cout << std::endl;
	{
		Bureaucrat b("Carl", 0);
		std::cout << b;
	}
	std::cout << std::endl;
	{
		Bureaucrat b("David", 149);
		b.decrementGrade();
		b.decrementGrade();
		b.decrementGrade();
		std::cout << b;
	}
	std::cout << std::endl;
	{
		Bureaucrat b("Eric", -7);
		std::cout << b;
	}
	std::cout << std::endl;

	return 0;
}
