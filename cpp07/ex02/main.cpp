#include "Array.hpp"

int main()
{
	std::cout << std::endl << "INTEGER ARRAY" << std::endl;
	{
		int array[] = {1435, 432, 65463};
		Array<int> intArray(3);
		intArray.setArray(array);
		std::cout << "\t" << "Size:                \033[0;33m" << intArray.size() << "\033[0;0m" << std::endl;
		std::cout << "\t" << "Array content:       \033[0;32m" << intArray << "\033[0;0m" << std::endl;
		try
		{
			std::cout << "\t" << intArray[5] << "\033[0;0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\033[0;31mException:           Index \"" << 5 << "\" out of bounds!\033[0;0m" << std::endl;
		}
	}
	std::cout << std::endl << "UNSIGNED INT ARRAY" << std::endl;
	{
		unsigned array[] = {567, 23244, 334543, 1, 42};
		Array<unsigned> uIntArray(5);
		uIntArray.setArray(array);
		std::cout << "\t" << "Size:                \033[0;33m" << uIntArray.size() << "\033[0;0m" << std::endl;
		std::cout << "\t" << "Array content:       \033[0;32m" << uIntArray << "\033[0;0m" << std::endl;
		try
		{
			std::cout << "\t" << uIntArray[7] << "\033[0;0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\033[0;31mException:           Index \"" << 7 << "\" out of bounds!\033[0;0m" << std::endl;
		}
	}
	std::cout << std::endl << "FLOAT ARRAY" << std::endl;
	{
		float array[] = {5461.14535f, 343.000233f};
		Array<float> floatArray(2);
		floatArray.setArray(array);
		std::cout << "\t" << "Size:                \033[0;33m" << floatArray.size() << "\033[0;0m" << std::endl;
		std::cout << "\t" << "Array content:       \033[0;32m" << floatArray << "\033[0;0m" << std::endl;
		try
		{
			std::cout << "\t" << floatArray[3] << "\033[0;0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\033[0;31mException:           Index \"" << 3 << "\" out of bounds!\033[0;0m" << std::endl;
		}
	}
	std::cout << std::endl << "CHAR* ARRAY" << std::endl;
	{
		char const *array[] = {"Hello", "world", "!"};
		Array<char const *> cStringArray(3);
		cStringArray.setArray(array);
		std::cout << "\t" << "Size:                \033[0;33m" << cStringArray.size() << "\033[0;0m" << std::endl;
		std::cout << "\t" << "Array content:       \033[0;32m" << cStringArray << "\033[0;0m" << std::endl;
		try
		{
			std::cout << "\t" << cStringArray[9] << "\033[0;0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\033[0;31mException:           Index \"" << 9 << "\" out of bounds!\033[0;0m" << std::endl;
		}
	}
	std::cout << std::endl << "STRING ARRAY" << std::endl;
	{
		std::string array[] = {"The ", "answer ", "to ", "the ", "universe."};
		Array<std::string> stringArray(5);
		stringArray.setArray(array);
		std::cout << "\t" << "Size:                \033[0;33m" << stringArray.size() << "\033[0;0m" << std::endl;
		std::cout << "\t" << "Array content:       \033[0;32m" << stringArray << "\033[0;0m" << std::endl;
		try
		{
			std::cout << "\t" << stringArray[11] << "\033[0;0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\033[0;31mException:           Index \"" << 11 << "\" out of bounds!\033[0;0m" << std::endl;
		}
	}
	std::cout << std::endl << "EMPTY INT ARRAY" << std::endl;
	{
		int *array = NULL;
		Array<int> emptyArray;
		emptyArray.setArray(array);
		std::cout << "\t" << "Size:                \033[0;33m" << emptyArray.size() << "\033[0;0m" << std::endl;
		std::cout << "\t" << "Array content:       \033[0;32m" << emptyArray << "\033[0;0m" << std::endl;
		try
		{
			std::cout << "\t" << emptyArray[0] << "\033[0;0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "\033[0;31mException:           Index \"" << 0 << "\" out of bounds!\033[0;0m" << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
