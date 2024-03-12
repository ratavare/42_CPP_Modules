#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (std::cout << "Bad arguments." << std::endl, 1);
	ScalarConverter::converter(argv[1]);
	return (0);
}