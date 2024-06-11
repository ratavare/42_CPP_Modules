#include "RPN.hpp"

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw RPN::Error("Invalid argument number.");
		RPN rpn(argv[1]);
		rpn.makeCalculations();
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}