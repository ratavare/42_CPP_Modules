#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	try
	{
		if (argc < 2)
			throw PmergeMe::Error("Invalid argument number.");
		PmergeMe  containers(argv);
		containers.sortVec();
	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	
}