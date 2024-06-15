#pragma once

#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <cerrno>
#include <climits>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deq;

	void populateContainers(char **argv);
	
public:
	PmergeMe(char **argv);
	~PmergeMe();

	class Error : public std::exception
	{
	private:
		const char *msg;
		virtual const char * what() const throw() {return msg;}
	public:
		Error(const char* _msg) : msg(_msg) {}
	};
};
