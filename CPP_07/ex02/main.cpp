#include "Array.hpp"

int main(void)
{
	try 
	{
		// Valid tests

		Array<int> a;
		Array<int> b(5);
		Array<char> c(3);

		// Setting values
		for (int i = 0; i < 5; i++)
			b[i] = i;

		// Copy assignment operator
		a = b;

		// Printing
		for (int i = 0; i < 5; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << "===========" << std::endl;

		// Setting values
		c[0] = 'o';
		c[1] = 'l';
		c[2] = 'a';

		// Printing
		for (int i = 0; i < 3; i++)
			std::cout << c[i];
		std::cout << std::endl;
		std::cout << "===========" << std::endl;

		// Invalid tests
		std::cout << c[10];
		std::cout << a[-1];
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}