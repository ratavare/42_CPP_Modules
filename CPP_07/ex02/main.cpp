#include "Array.hpp"

// int main(void)
// {
// 	try 
// 	{
// 		// Valid tests

// 		Array<int> a;
// 		Array<int> b(5);
// 		Array<char> c(3);

// 		// Setting values
// 		for (int i = 0; i < 5; i++)
// 			b[i] = i;

// 		// Copy assignment operator
// 		a = b;

// 		// Printing
// 		for (int i = 0; i < 5; i++)
// 			std::cout << a[i] << " ";
// 		std::cout << std::endl;
// 		std::cout << "===========" << std::endl;

// 		// Setting values
// 		c[0] = 'o';
// 		c[1] = 'l';
// 		c[2] = 'a';

// 		// Printing
// 		for (int i = 0; i < 3; i++)
// 			std::cout << c[i];
// 		std::cout << std::endl;
// 		std::cout << "===========" << std::endl;

// 		// Invalid tests
// 		std::cout << c[10];
// 		std::cout << a[-1];
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	}
// }

#include <iostream>
#include <cmath>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}