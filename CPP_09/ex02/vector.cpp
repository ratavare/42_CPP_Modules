#include "PmergeMe.hpp"

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
	if (pend.size() < 4)
		jacobsthalSeq.pop_back();
	if (pend.size() < 2)
		jacobsthalSeq.pop_back();

	mainChain.insert(mainChain.begin(), pend[0]);
	std::vector<int>::iterator it;
	for (size_t i = 1; i < jacobsthalSeq.size(); i++) {
		int pendPos = jacobsthalSeq[i];
		while (pendPos > jacobsthalSeq[i - 1]) {
			while (pendPos > static_cast<int>(pend.size()) - 1)
				pendPos--;
		it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[pendPos]);
		mainChain.insert(it, pend[pendPos--]);
		}
	}
	if (strangler) {
		it = std::lower_bound(mainChain.begin(), mainChain.end(), stranglerVal);
		mainChain.insert(it, stranglerVal);
	}
	vec.swap(mainChain);
}