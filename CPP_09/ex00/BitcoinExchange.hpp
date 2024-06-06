#pragma once

#include <iostream>
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
	std::map<std::string, int> data;
	std::queue<std::pair<std::string, int> > input;

public:
	BitcoinExchange() {};
	~BitcoinExchange() {};
	void parseData(const std::string path);
	void parseInput();

	class Error : public std::exception
	{
	private:
		const char *msg;
		virtual const char * what() const throw() {return msg;}
	public:
		Error(const char* _msg) : msg(_msg) {}
	};
};
