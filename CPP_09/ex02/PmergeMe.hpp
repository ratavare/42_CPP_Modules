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
#include <ctime>
#include <sys/time.h>

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

	void recursiveSort(std::vector<int>& sequence, int i);
	void recursiveSort(std::deque<int>& sequence, int i);
	std::deque<std::pair<int, int> >	makePairsDQ();
	std::vector<std::pair<int, int> >	makePairsV();

public:
	PmergeMe(char **argv);
	~PmergeMe();

	void sortDeq();
	void sortVec();
	std::vector<int> getVec();
	std::deque<int> getDeq();

	static void printVector(std::vector<int> container);
	static void printDeque(std::deque<int> container);

	class Error : public std::exception
	{
	private:
		const char *msg;
		virtual const char * what() const throw() {return msg;}
	public:
		Error(const char* _msg) : msg(_msg) {}
	};
};
