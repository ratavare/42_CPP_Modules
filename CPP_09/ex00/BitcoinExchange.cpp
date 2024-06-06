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

bool BitcoinExchange::validateInputLine(std::string line) {
	size_t fs = line.find_first_of(' ');
	size_t ls = line.find_last_of(' ');
	if (fs == std::string::npos || ls == std::string::npos)
		return std::cerr << "Value missing: " << line << std::endl, false;
	if (fs == ls || !std::isdigit(line[fs - 1]) || (line[ls + 1] && !std::isdigit(line[ls + 1])))
		return std::cerr << "Bad input: " << line << std::endl, false;
	size_t i = 0;
	while (line[i] != ' ') {
		if (i < 4 && !std::isdigit(line[i]))
			continue ;
		else if (i > 4 && i < 7 && !std::isdigit(line[i]))
			continue ;
		else if (i > 7 && i < 10 && !std::isdigit(line[i]))
			continue ;
		else if ((i == 4 || i == 7) && line[i] == '-')
			continue ;
		else
			return std::cerr << "Bad date format: " << line << std::endl, false;
	}
	return true;
}

void BitcoinExchange::printValue(std::string line) {
	std::string date = line.substr(0, line.find_first_of(' '));
	std::string value = line.substr(line.find_last_of(' '));
	std::cout << date << " " << value << std::endl;

	//TODO: Finish this.
}

void BitcoinExchange::processInput(std::string argv) {
	std::ifstream file(argv.c_str());
	if (!file)
		throw Error("Input file does not exist or is unreachable.");
	std::string line;
	while (std::getline(file, line)) {
		if (validateInputLine(line)) {
			printValue(line);
		}
	}
	file.close();
}