#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void convertToChar(std::string str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		std::cout << "char: '" << str << "'" << std::endl;
		return ;
	}
	else {
		std::cout << "char: ";
		if (str.length() > 1 && (str[0] == '+' || str[0] == '-') && isdigit(str[1])) {
			double val = atof(str.c_str());
			if (val < 0 || val > 127 || std::isnan(val) || std::isinf(val))
				throw ScalarConverter::ImpossibleException();
			if (std::isprint(static_cast<char>(val))) {
				std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
				return ;
			}
			else
				throw ScalarConverter::NonPrintableException();
		}
		throw ScalarConverter::ImpossibleException();
	}
}

void ScalarConverter::converter(std::string str) {
	convertToChar(str);
}