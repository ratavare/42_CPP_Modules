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

int Span::operator[](unsigned int i) {
	return array[i];
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
	if (array.size() < 2)
		throw NoNumbersException();
	int lowestSpan = INT_MAX;
	std::vector<int>	tmp_array;
	tmp_array = array;
	std::sort(tmp_array.begin(), tmp_array.end());
	for (std::vector<int>::size_type i = 1; i < tmp_array.size(); i++) {
		int diff = std::abs(tmp_array[i] - tmp_array[i - 1]);
		if (diff < lowestSpan)
			lowestSpan = diff;
	}
	return (lowestSpan);
}

int Span::longestSpan() {
	return (max - min);
}

void Span::spanFill(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (array.size() + std::distance(begin, end) > array.capacity())
		throw SpanFullException();
	for (std::vector<int>::iterator it = begin; it < end; it++) {
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	array.insert(array.end(), begin, end);		
}