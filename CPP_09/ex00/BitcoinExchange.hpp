#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

class BitcoinExchange
{
private:
	std::map<std::string, float> data;
	std::queue<std::pair<std::string, double> > input;

	bool validateInputLine(std::string line);
	void printValue(std::string line);

public:
	BitcoinExchange() {};
	~BitcoinExchange() {};
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
