#include "BitcoinExchange.cpp"

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw BitcoinExchange::Error("Invalid argument number.");
		BitcoinExchange bitEx;
		bitEx.parseData("data.csv");
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}
