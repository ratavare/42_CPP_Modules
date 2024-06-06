#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw BitcoinExchange::Error("Invalid argument number.");
		BitcoinExchange bitEx;
		bitEx.parseData("data.csv");
		bitEx.processInput(std::string(argv[1]));
	}
	catch (const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
}
