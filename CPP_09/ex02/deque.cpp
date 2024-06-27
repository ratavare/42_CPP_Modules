#include "PmergeMe.hpp"

std::deque<std::pair<int, int> > PmergeMe::makePairsDQ() {
	std::deque<std::pair<int, int> > pairs;
	
	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
	}
	if (deq.size() % 2) {
		strangler = true;
		stranglerVal = deq.back();
	}
	return pairs;
}

void PmergeMe::sortDeq() {
	std::deque<std::pair<int, int> > pairs = makePairsDQ();
	for (size_t i = 0; i != pairs.size(); i++)
		if (pairs[i].first < pairs[i].second)
			PmergeMe::swap(pairs[i].first, pairs[i].second);
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	std::deque<int> pend;
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
	std::deque<int>::iterator it;
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
	deq.swap(mainChain);
}