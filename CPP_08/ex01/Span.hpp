#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
private:
	std::vector<int>	array;
	int 				max;
	int					min;
	Span() {}
public:
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	int operator[](unsigned int i);
	~Span();

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	void spanFill(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return "Span is full";
		}
	};
	
	class NoNumbersException : public std::exception
	{
	public:
		virtual const char *what() const throw() {
			return "No span can be found";
		}
	};
};
