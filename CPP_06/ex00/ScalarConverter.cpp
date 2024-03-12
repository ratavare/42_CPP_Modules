#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

int getType(std::string str) {
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" ||
	str == "+inf" ||  str == "nan" || str == "inf" || str == "inff")
		return PSEUDOLITERAL;
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	int flag[2] = {0, 0};
	for (size_t i = 0; i < (str.length()); i++) {
		if (!isdigit(str[i]) && str[i] != '.' &&
		str[i] != 'f' && str[i] != '-' && str[i] != '+')
			return INVALID;
		if (str[i] == '.' && !str[i + 1])
			return INVALID;
		else if (str[i] == '.')
			flag[0] = 1;
		else if (str[i] == 'f')
			flag[1] = 1;
	}
	if (!flag[0] && !flag[1])
		return INT;
	else if (flag[0] && !flag[1])
		return DOUBLE;
	return FLOAT;
}

void printChar(int c) {
	std::cout << "char: ";
	if (c > 126 || c < 0)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(long n) {
	std::cout << "int: ";
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
}

void printFloat(double n) {
	std::cout << "float: ";
	if (n > FLT_MAX || n < FLT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << static_cast<float>(n) << "f" << std::endl;
}

void printDouble(double n) {
	std::cout << "double: ";
	if (n == INFINITY || n == -INFINITY)
		std::cout << "impossible" << std::endl;
	else
		std::cout << n << std::endl;
}

void impossible4all(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void convertFromChar(char c) {
	printChar(c);
	printInt(static_cast<long>(c));
	printFloat(static_cast<double>(c));
	printDouble(static_cast<double>(c));
}

void convertFromInt(long n) {
	if (n > INT_MAX || n < INT_MIN) {
		impossible4all();
		return ;
	}
	printChar(static_cast<int>(n));
	printInt(n);
	printFloat(static_cast<double>(n));
	printDouble(static_cast<double>(n));
}

void convertFromFlouble(double n) {
	printChar(static_cast<int>(n));
	printInt(static_cast<long>(n));
	printFloat(n);
	printDouble(n);
}

void printNonLiteral(std::string str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "inf" || str == "inff" || str == "+inf" ||
	str == "+inff") {
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::converter(std::string str) {
	int type = getType(str);
	if (type == CHAR)
		convertFromChar(str[0]);
	else if (type == INT)
		convertFromInt(atol(str.c_str()));
	else if (type == FLOAT || type == DOUBLE)
		convertFromFlouble(atof(str.c_str()));
	else if (type == INVALID)
		std::cout << "Invalid Argument" << std::endl;
	else
		printNonLiteral(str);
}