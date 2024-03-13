#include "iter.hpp"

int main( void )
{
	int array[] = {0, 1, 2, 3, 4, 5};


	std::cout << "BEFORE ITER:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << array[i] << std::endl;

	iter(array, 6, &setToZero);

	std::cout << std::endl << "AFTER ITER:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << array[i] << std::endl;
}