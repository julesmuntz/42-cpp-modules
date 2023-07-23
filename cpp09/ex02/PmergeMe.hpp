#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <climits>
#include <iomanip>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &copy);
	PmergeMe &operator=(PmergeMe const &copy);
};
