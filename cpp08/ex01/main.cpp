#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);
		// Span sp = Span(10);
		// std::vector<int> vec(10);

		// sp.addNumbers(vec.begin(), vec.end());
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(5);
		// sp.addNumber(42);
		// sp.addNumber(23);

		// for (unsigned i = 0; i < sp.getVector().size(); ++i)
		// 	std::cout << sp.getVector()[i] << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::ContainerFullException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Span::ContainerEmptyException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Span::LessThanTwoException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
