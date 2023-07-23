#include "PmergeMe.hpp"

void insertSort(std::deque<int> &deq, double &elapsedTime)
{
	timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	int key, j;
	for (int i = 1; i < static_cast<int>(deq.size()); ++i)
	{
		key = deq[i];
		j = i - 1;
		while (j >= 0 && deq[j] > key)
		{
			deq[j + 1] = deq[j];
			--j;
		}
		deq[j + 1] = key;
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	elapsedTime += (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;
}

void mergeSort(std::vector<int> &A, int p, int q, int r, double &elapsedTime)
{
	timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	std::vector<int> LA(A.begin() + p, A.begin() + q + 1);
	std::vector<int> RA(A.begin() + q + 1, A.begin() + r + 1);
	int i = 0, j = 0, k = p;
	while (i < static_cast<int>(LA.size()) && j < static_cast<int>(RA.size()))
	{
		if (LA[i] <= RA[j])
			A[k++] = LA[i++];
		else
			A[k++] = RA[j++];
	}
	while (i < static_cast<int>(LA.size()))
		A[k++] = LA[i++];
	while (j < static_cast<int>(RA.size()))
		A[k++] = RA[j++];
	clock_gettime(CLOCK_MONOTONIC, &end);
	elapsedTime += (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;
}

void sort(std::vector<int> &A, int p, int r, double &insertTime, double &mergeTime)
{
	if (r - p > 2)
	{
		int q = (p + r) / 2;
		sort(A, p, q, insertTime, mergeTime);
		sort(A, q + 1, r, insertTime, mergeTime);
		mergeSort(A, p, q, r, mergeTime);
	}
	else
	{
		std::deque<int> deq(A.begin() + p, A.begin() + r + 1);
		insertSort(deq, insertTime);
		std::copy(deq.begin(), deq.end(), A.begin() + p);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "\033[31mError: no arguments (numbers) to sort.\033[0m" << std::endl;
		return 1;
	}
	std::vector<int> arr;
	for (int i = 1; i < ac; i++)
	{
		std::istringstream iss(av[i]);
		int val = 0;
		iss >> val;
		if (iss.fail() || !iss.eof() || val < 0 || val > INT_MAX)
		{
			std::cerr << "\033[31mError: invalid argument(s).\033[0m" << std::endl;
			return 1;
		}
		arr.push_back(val);
	}
	std::cout << "Before:  ";
	for (int i = 0; i < static_cast<int>(arr.size()); i++)
	{
		if (i == 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << arr[i] << " ";
	}
	double tempInsertTime = 0.0, tempMergeTime = 0.0;
	sort(arr, 0, arr.size() - 1, tempInsertTime, tempMergeTime);
	double insertTime = tempInsertTime;
	double mergeTime = tempMergeTime;
	std::cout << std::endl
			  << "After:   ";
	for (int i = 0; i < static_cast<int>(arr.size()); i++)
	{
		if (i == 5)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << arr.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << mergeTime << " us" << std::endl;
	std::cout << "Time to process a range of " << arr.size() << " elements with std::deque  : " << std::fixed << std::setprecision(3) << insertTime << " us" << std::endl;
	return 0;
}
