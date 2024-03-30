#include "easyfind.hpp"

int main(void)
{
	std::vector<int> numbers;

	for (int i = 1; i <= 50; i++) {
		numbers.push_back(i);
	}
	int* res = easyfind(numbers, 51);
	if (res)
		std::cout << "value found at " << res << std::endl;
	else
		std::cout << "value not found :C" << std::endl;
}