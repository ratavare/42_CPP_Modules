#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	ScalarConverter::converter(argv[1]);
	return (0);
}