#include "PmergeMe.hpp"

/*
	Creates pairs from all the values in private varialble 'deq' allocating them
	in a deque of pairs. If number of elements is odd, defines private variable strangler
	as true and defines stranglerVal as the value of the leftover element.
*/

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

/*
	Uses Ford Johnson Merge Insertion Sort algorithm to sort the elements present
	in 'deq'. Allocates these into local container 'mainChain' and later swaps 'deq'
	for this same container.
*/

void PmergeMe::sortDeq() {
	std::deque<std::pair<int, int> > pairs = makePairsDQ(); // Creating pairs.
	for (size_t i = 0; i != pairs.size(); i++)
		if (pairs[i].first < pairs[i].second)
			PmergeMe::swap(pairs[i].first, pairs[i].second); // Ordering pairs, bigger values first.
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++) // Populating mainChain with the pair's first values.
		mainChain.push_back(pairs[i].first);
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++) // Populating pend with the pair's second values.
		pend.push_back(pairs[i].second);

	// Sorting both containers unsing recusive insertion sort.
	recursiveSort(mainChain, mainChain.size() - 1);
	recursiveSort(pend, pend.size() - 1);

	// Creating Jacobsthal sequence. Removing any extra sequence numbers depending on size
	// so the algorithm is precise.
	std::vector<int> jacobsthalSeq = jacobsthalIndexSequenceGen(pend.size());
	if (pend.size() < 4)
		jacobsthalSeq.pop_back();
	if (pend.size() < 2)
		jacobsthalSeq.pop_back();

	// FJMI Sort.
	mainChain.insert(mainChain.begin(), pend[0]); // Inserting first element.
	std::deque<int>::iterator it;
	for (size_t i = 1; i < jacobsthalSeq.size(); i++) { // Iterating through the Jacobsthal sequence
		int pendPos = jacobsthalSeq[i];					// for the index of the next insertion element in pend.
		while (pendPos > jacobsthalSeq[i - 1]) {
			while (pendPos > static_cast<int>(pend.size()) - 1)
				pendPos--;
		it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[pendPos]); // Binary search to find the optimal
		mainChain.insert(it, pend[pendPos--]);									  // position for the element and inserting it.
		}
	}
	if (strangler) {
		it = std::lower_bound(mainChain.begin(), mainChain.end(), stranglerVal); // Inserting the strangler if it exists.
		mainChain.insert(it, stranglerVal);
	}
	deq.swap(mainChain); // Swaping 'deq' for 'mainChain' (saves time in deletion and allocation).
}