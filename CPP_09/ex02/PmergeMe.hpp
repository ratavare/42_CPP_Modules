#pragma once

#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <cerrno>
#include <climits>
#include <utility>

class PmergeMe
{
private:
	std::vector<int>	vec;
	std::deque<int>		deq;
	bool				strangler;
	int 				stranglerVal;

	static void			swap(int& x, int& y);
	void				populateContainers(char **argv);
	std::vector<int>	jacobsthalIndexSequenceGen(int limit);

	void 				recursiveSort(std::vector<int>& sequence, int i);
	void				makePairsDQ();
	std::vector<std::pair<int, int> > makePairsV();

public:
	PmergeMe(char **argv);
	~PmergeMe();

	void sortDeq();
	void sortVec();

	class Error : public std::exception
	{
	private:
		const char *msg;
		virtual const char * what() const throw() {return msg;}
	public:
		Error(const char* _msg) : msg(_msg) {}
	};
};
