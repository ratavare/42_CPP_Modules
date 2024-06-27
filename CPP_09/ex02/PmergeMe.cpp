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

void PmergeMe::sortVec() {
	std::vector<std::pair<int, int> > pairs = makePairsV();
	for (size_t i = 0; i != pairs.size(); i++)
		if (pairs[i].first < pairs[i].second)
			PmergeMe::swap(pairs[i].first, pairs[i].second);
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);
	recursiveSort(mainChain, mainChain.size() - 1);
	recursiveSort(pend, pend.size() - 1);
	std::vector<int> jacobsthalSeq = jacobsthalIndexSequenceGen(pend.size());

	std::cout << "----Pairs----" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;

	std::cout << "----MainChain----" << std::endl;
	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << std::endl;

	std::cout << "----Pend----" << std::endl;
	for (size_t i = 0; i < pend.size(); i++)
		std::cout << pend[i] << std::endl;

	std::cout << std::endl << "JacobsthalSeq: ";
	for (size_t i  = 0; i < jacobsthalSeq.size(); i++)
		std::cout << jacobsthalSeq[i] << " ";
	std::cout << std::endl << std::endl;

	mainChain.insert(mainChain.begin(), pend[0]);
	for (size_t i = 1; i < jacobsthalSeq.size(); i++) {
		int pendPos = jacobsthalSeq[i];
		while (pendPos != jacobsthalSeq[i - 1]) {
			while (pendPos > static_cast<int>(pend.size()) - 1)
				pendPos--;
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[pendPos]);
		mainChain.insert(it, pend[pendPos--]);
		}
	}

	/* For testing purposes. */
	std::cout << "----Pairs----" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	if (strangler)
		std::cout << "strangler: " << stranglerVal << std::endl;
	std::cout << "----Sorted MainChain----" << std::endl;
	for (size_t i = 0; i < mainChain.size(); i++)
	std::cout << mainChain[i] << std::endl;
}
