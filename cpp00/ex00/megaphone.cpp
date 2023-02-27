#include <iostream>
using namespace std;
int main(int ac, char **av) {
	if(ac < 2)
		return cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0;
	for(int n = 1; n < ac; n++)
	{
		for(int i = 0; av[n][i]; i++)
			cout << (char)toupper(av[n][i]);
		cout << " ";
	}
	cout << "\n";
	return 0;
}
