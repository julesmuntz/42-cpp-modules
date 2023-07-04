#include "MutantStack.hpp"

template <typename T>
static void printStack(MutantStack<T> mstack)
{
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << std::endl << "[Current stack]" << std::endl << "---------------" << std::endl;
	while (it != ite)
	{
		--ite;
		std::cout << "\t" << *ite << std::endl;
	}
	std::cout << "---------------" << std::endl << std::endl;
}

template <typename T>
static void printInfo(MutantStack<T> mstack)
{
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Top value: " << mstack.top() << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(42);
	printStack(mstack);
	printInfo(mstack);
	mstack.pop();
	mstack.push(33);
	mstack.push(77);
	mstack.push(800);
	mstack.push(23);
	mstack.push_back(789);
	printStack(mstack);
	printInfo(mstack);
	std::stack<int> s(mstack);
	return 0;
}
