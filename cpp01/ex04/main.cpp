#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return std::cout << "arg1: filename" << std::endl
					<< "arg2: to_find" << std::endl
					<< "arg3: replace" << std::endl, 0;

	std::string		filename = av[1];
	std::string		to_find = av[2];
	std::string		replace = av[3];
	std::string		line;
    std::ifstream	file(filename.c_str());
	bool		found = false;
	std::string 		rep_line;
	size_t		index = 0;

	if (!file.is_open())
		return std::cout << "File not found" << std::endl, 0;
	while (getline(file, line))
	{
		while (line.find(to_find) != std::string::npos)
		{
			found = true;
			line.erase(index, to_find.length());
			line.insert(index, replace);
		}
		rep_line += line + "\n";
	}
	if (found == true)
	{
		std::string		rep_filename = filename + ".replace";
		std::ofstream	rep_file(rep_filename.c_str());
		rep_file << rep_line;
		rep_file.close();
	}
	else
		std::cout << "Nothing to replace" << std::endl;
	return 0;
}