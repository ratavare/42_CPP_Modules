#pragma once

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
	MutantStack& operator=(const MutantStack& copy) {
		std::stack<T>::operator=(copy);
		return *this;
	}
	~MutantStack() {}

	iterator begin() {return std::stack<T>::c.begin();}
	iterator end() {return std::stack<T>::c.end();}

};
