#include "Span.hpp"

Span::Span(unsigned int N) : max(INT_MIN), min(INT_MAX) {
	array.reserve(N);
}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	if (this != &copy) {
		this->array = copy.array;
		this->max = copy.max;
		this->min = copy.min;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (array.size() == array.capacity())
		throw SpanFullException();
	if (number < min)
		min = number;
	if (number > max)
		max = number;
	array.push_back(number);
}

int Span::shortestSpan() {
	int tmp_min = this->min;
	int count = std::count(array.begin(), array.end(), tmp_min);

	std::vector<int>::iterator minIt = std::find(array.begin(), array.end(), tmp_min); 
	array.erase(std::remove(array.begin(), array.end(), tmp_min), array.end());
}