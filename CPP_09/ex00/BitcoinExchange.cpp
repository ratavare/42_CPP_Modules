#include "BitcoinExchange.hpp"

void BitcoinExchange::parseData(const std::string path) {
	std::ifstream file(path.c_str());
	if (!file)
		throw Error("data.csv file does not exist or is unreachable.");
	std::string line;
	while (std::getline(file, line)) {
		size_t delimiter = line.find(',');
		std::string key = line.substr(0, delimiter);
		float value = std::atof(line.substr(delimiter + 1).c_str());
		this->data.insert(std::make_pair(key, value));
	}
	file.close();
}

bool BitcoinExchange::isSingleNumber(std::string line) {
	int count = 0;
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
		if (!std::isdigit(*it) && *it != '.')
			count++;
	if (count > 0)
		return false;
	return true;
}

int BitcoinExchange::countChar(std::string line, int c) {
	int count = 0;
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
		if (*it == c)
			count++;
	return count;
}

std::string BitcoinExchange::trimWhiteSpaces(std::string line) {
	size_t begin = line.find_first_not_of(" \f\n\r\t\v");
	size_t end = line.find_last_not_of(" \f\n\r\t\v");
	return line.substr(begin, end + 1);
}

std::string* BitcoinExchange::splitDate(std::string line) {
	size_t pos = line.find('-');
	std::string* strs = new std::string[3];
	size_t j = 0;
	while (pos != std::string::npos) {
		strs[j] = line.substr(0, pos);
		line = line.substr(pos + 1);
		pos = line.find('-');
		j++;
	}
	strs[j] = line.substr(0, line.find(' '));
	return strs;
}

bool BitcoinExchange::validateDate(std::string* strs) {
	for (int i = 0; i < 3; i++)
		if (strs[i].empty())
			return delete[] strs, false;
	int vals[3];
	for (int i= 0; i < 3; i++)
		vals[i] = std::atoi(strs[i].c_str());
	if (vals[0] == 2009 && vals[1] == 1 && vals[2] == 1)
		return delete[] strs, false;
	if (strs[0].size() != 4 || vals[0] < 2009 || vals[0] > 2022)
		return delete[] strs, false;
	if (vals[1] < 1 || vals[1] > 12)
		return delete[] strs, false;
	int shortMonths[] = {4, 6, 9, 11};
	if (strs[1].size() == 2 && strs[2].size() == 2) {
		for (int i = 0; i < 4; i++)
			if (vals[1] == shortMonths[i]) {
				if (vals[2] > 30)
					return delete[] strs, false;
			}
			else if (vals[1] == 2) {
				if (vals[2] > 29)
					return delete[] strs, false;
			}
			else
				if (vals[2] > 31)
					return delete[] strs, false;
	}
	else
		return delete[] strs, false;
	return true;
}

bool BitcoinExchange::validateInputLine(std::string line) {
	if (countChar(line, '-') != 2 || countChar(line, '|') != 1 || countChar(line, '.') > 1)
		return std::cerr << "Bad input: " << line << std::endl, false;
	if (!isSingleNumber(trimWhiteSpaces(line.substr(line.find('|') + 1))))
		return std::cerr << "Too many values: " << line << std::endl, false;
	size_t fs = line.find_first_of(' ');
	size_t ls = line.find_last_of(' ');
	if (fs == std::string::npos || ls == std::string::npos)
		return std::cerr << "Value missing: " << line << std::endl, false;
	if (fs == ls || !std::isdigit(line[fs - 1]) || (line[ls + 1] && !std::isdigit(line[ls + 1])))
		return std::cerr << "Bad input: " << line << std::endl, false;
	if (std::atoll(line.substr(ls).c_str()) > 1000)
		return std::cerr << "Value too large: " << line << std::endl, false;
	std::string* strs = splitDate(line);
	if (!validateDate(strs))
		return std::cerr << "Invalid date format: " << line << std::endl, false;
	delete[] strs;
	return true;
}

std::string BitcoinExchange::decreaseDate(std::string date) {
	std::string* strs = splitDate(date);
	int year = std::atoi(strs[0].c_str());
	int month = std::atoi(strs[1].c_str());
	int day = std::atoi(strs[2].c_str());

	if (day == 1) {
		if (month == 1) {
			year--;
			month = 12;
			day = 31;
		}
		else
			month--;
	}
	else
		day--;
	std::stringstream ss;
	ss << year << "-";
	if (month > 9)
		ss << month << "-";
	else
		ss << "0" << month << "-";
	if (day > 9)
		ss << day;
	else
		ss << "0" << day;
	delete[] strs;
	return ss.str();
}

void BitcoinExchange::printValue(std::string line) {
	std::string date = line.substr(0, line.find_first_of(' '));
	std::string value = line.substr(line.find_last_of(' ') + 1);
	std::cout << date << " => " << value;
	if (data[date])
		std::cout << " = " << data[date] * std::atof(value.c_str()) << std::endl;
	else {
		while (!data[date])
			date = decreaseDate(date);
		std::cout << " = " << data[date] * std::atof(value.c_str()) << std::endl;
	}
}

void BitcoinExchange::processInput(std::string argv) {
	std::ifstream file(argv.c_str());
	if (!file)
		throw Error("Input file does not exist or is unreachable.");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw Error("Missing data types identifier.");
	while (std::getline(file, line)) {
		line = trimWhiteSpaces(line);
		if (validateInputLine(line))
			printValue(line);
	}
	file.close();
}