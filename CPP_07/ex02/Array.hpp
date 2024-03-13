#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	unsigned int size;
	T* elements;
public:
	Array() : size(0), elements(NULL) {}

	Array(unsigned int n) : size(n), elements(new T[n]) {}

	Array(const Array& copy) {
		*this = copy;
	}

	~Array() {
		delete[] this->elements;
	}

	Array& operator=(const Array& copy) {
		if (this != &copy) {
			if (this->elements)
				delete[] elements;
			this->size = copy.getSize();
			this->elements = new T[this->size];
			for (unsigned int i = 0; i < this->size; i++)
				this->elements[i] = copy.elements[i];
		}
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index >= this->size)
			throw Array::OutOfBoundsException();
		return elements[index];
	}

	unsigned int getSize(void) const {return this->size;}
	
	class OutOfBoundsException : public std::exception
	{
	public:
		const char* what() const throw() {
			return "Out of bounds.";
		}
	};
};