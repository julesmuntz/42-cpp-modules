#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main(int ac, char **av)
{
	if (ac != 4)
		return cout << "arg1: filename" << endl
					<< "arg2: to_find" << endl
					<< "arg3: replace" << endl, 0;

	string		filename = av[1];
	string		to_find = av[2];
	string		replace = av[3];
	string		line;
    ifstream	file(filename.c_str());
	bool		found = false;
	string 		rep_line;
	size_t		index = 0;

	if (!file.is_open())
		return cout << "File not found" << endl, 0;
	while (getline(file, line))
	{
		while (line.find(to_find) != string::npos)
		{
			found = true;
			line.erase(index, to_find.length());
			line.insert(index, replace);
		}
		rep_line += line + "\n";
	}
	if (found == true)
	{
		string		rep_filename = filename + ".replace";
		ofstream	rep_file(rep_filename.c_str());
		rep_file << rep_line;
		rep_file.close();
	}
	else
		cout << "Nothing to replace" << endl;
	return 0;
}