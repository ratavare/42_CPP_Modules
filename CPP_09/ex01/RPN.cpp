#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) {(void)copy;}

RPN& RPN::operator=(const RPN& copy) {
	(void)copy;
	return *this;
}

RPN::RPN(char* argv) : input(std::string(argv)) {
	if (this->input.empty())
		throw Error("Empty input. :(");
}

bool RPN::isOperator(int c) {
	return (c == '/' || c == '*' || c == '+' || c == '-');
}

double RPN::makeOperation(double _operand1, double _operand2, int _operator) {
	switch (_operator)
	{
	case '*':
		return _operand2 * _operand1;
	case '/':
		return _operand2 / _operand1;
	case '+':
		return _operand2 + _operand1;
	case '-':
		return _operand2 - _operand1;
	}
	return -1;
}

void RPN::makeCalculations() {
	double val = 0;
	double operand1 = 0;
	double operand2 = 0;
	
	for (size_t i = 0; i != input.size(); i++) {
		if (std::isdigit(input[i])) {
			val = std::atoi(input.substr(i).c_str());
			if (val > 9)
				throw Error("Invalid value present in input string (only 0-9 allowed).");
			stack.push(val);
		}
		else if (isOperator(input[i])) {
			if (stack.size() < 2)
				throw Error("Input is not in RPN form.");
			operand1 = stack.top();
			stack.pop();
			operand2 = stack.top();
			stack.pop();
			stack.push(makeOperation(operand1, operand2, input[i]));
		}
		else if (std::isspace(input[i]))
			continue ;
		else
			throw Error("Invalid character passed as argument.");
	}
	std::cout << "Result: " << stack.top();
}