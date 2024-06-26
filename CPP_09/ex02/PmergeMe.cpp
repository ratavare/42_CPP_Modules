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
	Populates private vector 'jacobsthal' with the jacobsthal sequece
	and ajusts all the values to be used as indexes.
*/

void PmergeMe::jacobsthalIndexSequenceGen(int limit) {
	int j0 = 1, j1 = 3, jn;
	jacobsthal.push_back(0);
	jacobsthal.push_back(2);
	
	while (true) {
		jn = j1 + 2 * j0;
		if (jn > limit)
			break;
		jacobsthal.push_back(jn - 1);
		j0 = j1;
		j1 = jn;
	}
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
}

std::vector<std::pair<int, int> > PmergeMe::makePairsV() {
	std::vector<std::pair<int, int> > pairs;
	
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	if (vec.size() % 2) {
		strangler = true;
		stranglerVal = vec.back();
	}
	return pairs;
}

void PmergeMe::sortMainChain(std::vector<int>& mainChain, int i) {
	if (i <= 0)
		return ;
	sortMainChain(mainChain, i - 1);
	for (;i > 0 && mainChain[i] < mainChain[i - 1]; i--)
		PmergeMe::swap(mainChain[i], mainChain[i - 1]);
}

void PmergeMe::sortVec() {
	std::vector<std::pair<int, int> > pairs = makePairsV();
	for (size_t i = 0; i != pairs.size(); i++)
		if (pairs[i].first < pairs[i].second)
			PmergeMe::swap(pairs[i].first, pairs[i].second);

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	sortMainChain(mainChain, mainChain.size() - 1);


	/* For testing purposes. */
	std::cout << "----Pairs----" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	if (strangler)
		std::cout << "strangler: " << stranglerVal << std::endl;
	std::cout << "----MainChain----" << std::endl;
	for (size_t i = 0; i < mainChain.size(); i++)
	std::cout << mainChain[i] << std::endl;
}
