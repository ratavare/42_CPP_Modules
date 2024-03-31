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
	~Span();

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

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
