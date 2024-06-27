#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** argv) : strangler(false) {populateContainers(argv);}

PmergeMe::~PmergeMe() {}

/*
	Swaps the two values.
*/

void PmergeMe::swap(int& x, int& y) {
	x = x ^ y;
	y = x ^ y;
	x =  x ^ y;
}

/*
	Returns vector 'jacobsthal' with the jacobsthal sequence until one
	value after the limit passed as a parameter and ajusts all the values 
	to be used as indexes.
*/

std::vector<int> PmergeMe::jacobsthalIndexSequenceGen(int limit) {
	std::vector<int> jacobsthal;
	int j0 = 1, j1 = 3, jn;
	jacobsthal.push_back(0);
	jacobsthal.push_back(2);
	
	while (true) {
		jn = j1 + 2 * j0;
		jacobsthal.push_back(jn - 1);
		if (jn > limit)
			break;
		j0 = j1;
		j1 = jn;
	}
	return jacobsthal;
}

/*
	Parses and populates the private vector and deque variables
	with the program's input.
*/

void PmergeMe::populateContainers(char **argv) {
	std::string arg;
	int val;
	for (size_t i = 1; argv[i] != NULL; i++) {
		arg = argv[i];
		if (arg.find_first_not_of("0123456789") != std::string::npos)
			throw Error("Invalid argument(s) present.");
		errno = 0;
		val = std::atoi(argv[i]);
		if (errno == ERANGE)
			throw Error("Integer overflow present.");
		vec.push_back(val);
		deq.push_back(val);
	}
	if (vec.size() == 1 || deq.size() == 1)
		throw Error("Only one value given. (2 or more required)");
}

/*
	Performs recursive insertion sort algorithm.
*/

void PmergeMe::recursiveSort(std::vector<int>& sequence, int i) {
	if (i <= 0)
		return ;
	recursiveSort(sequence, i - 1);
	for (;i > 0 && sequence[i] < sequence[i - 1]; i--)
		PmergeMe::swap(sequence[i], sequence[i - 1]);
}

void PmergeMe::recursiveSort(std::deque<int>& sequence, int i) {
	if (i <= 0)
		return ;
	recursiveSort(sequence, i - 1);
	for (;i > 0 && sequence[i] < sequence[i - 1]; i--)
		PmergeMe::swap(sequence[i], sequence[i - 1]);
}