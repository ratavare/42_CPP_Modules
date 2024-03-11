#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <climits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
public:
	static void converter(std::string str);

	class ImpossibleException : public std::exception
	{
	public:
		const char* what() const throw() {
			return "Impossible";
		}
	};
	class NonPrintableException : public std::exception
	{
	public:
		const char* what() const throw() {
			return "Non displayable";
		}
	};
};
