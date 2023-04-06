#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main(int ac, char **av)
{
	if (ac != 4)
		return cout << "arg1: filename" << endl
					<< "arg2: to_find" << endl
					<< "arg3: to_replace" << endl, 0;

	string		filename = av[1];
	string		to_find = av[2];
	string		to_replace = av[3];
	string		line;
    ifstream	file(filename.c_str());

	if (!file.is_open())
		return cout << "File not found" << endl, 0;
	while (getline(file, line))
	{
		if (line.find(to_find) != string::npos)
			cout << "To be replaced" << endl;	//tmp
	}
	return 0;
}