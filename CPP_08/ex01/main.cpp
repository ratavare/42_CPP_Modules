#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main()
{
	Span sp(100000);
	srand(time(0));
	try
	{
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		for (int i = 0; i < 50000; i++)
			sp.addNumber(rand());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::vector<int> tmp(50000);
		std::fill(tmp.begin(), tmp.end(), 5);
		sp.spanFill(tmp.begin(), tmp.end() - 1);
		std::cout << sp[99999] << std::endl;
		sp.addNumber(1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}