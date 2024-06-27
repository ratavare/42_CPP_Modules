#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> data;

	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);

	std::string* splitDate(std::string line);
	int countChar(std::string line, int c);
	bool isSingleNumber(std::string line);
	std::string trimWhiteSpaces(std::string line);
	bool validateInputLine(std::string line);
	bool validateDate(std::string* strs);
	std::string decreaseDate(std::string line);
	void printValue(std::string line);

public:
	BitcoinExchange();
	~BitcoinExchange();
	void parseData(const std::string path);
	void processInput(std::string argv);

	class Error : public std::exception
	{
	private:
		const char *msg;
		virtual const char * what() const throw() {return msg;}
	public:
		Error(const char* _msg) : msg(_msg) {}
	};
};
