#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iomanip>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
	PSEUDOLITERAL
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
public:
	static void converter(std::string str);
};

