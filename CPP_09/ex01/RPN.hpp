#pragma once

#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <list>
#include <iostream>

class RPN
{
private:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);

	std::stack<double, std::list<double> > stack;
	std::string input;

	bool isOperator(int c);
	double makeOperation(double _operand1, double _operand2, int _operator);

public:
	RPN(char* argv);
	~RPN();
	
	void makeCalculations();

	class Error : public std::exception
	{
	private:
		const char *msg;
		virtual const char * what() const throw() {return msg;}
	public:
		Error(const char* _msg) : msg(_msg) {}
	};
};