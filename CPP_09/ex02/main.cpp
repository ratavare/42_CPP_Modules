#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	try
	{
		if (argc < 2)
			throw PmergeMe::Error("Invalid argument number.");
		PmergeMe  containers(argv);
		std::clock_t vector_start, vector_end, deque_start, deque_end;
		double vector_time, deque_time;

		std::cout << "----Vector----" << std::endl;
		std::cout << "Before: ";
		PmergeMe::printVector(containers.getVec());
		vector_start = std::clock();
		containers.sortVec();
		vector_end = std::clock();
		std::cout << "After: ";
		PmergeMe::printVector(containers.getVec());
		vector_time = static_cast<double>(vector_end - vector_start) * 1000 / CLOCKS_PER_SEC;
		std::cout << "Time taken: " << vector_time << "ms" << std::endl;

		containers.resetStrangler();

		std::cout << "----Deque----" << std::endl;
		std::cout << "Before: ";
		PmergeMe::printDeque(containers.getDeq());
		deque_start = std::clock();
		containers.sortDeq();
		deque_end = std::clock();
		std::cout << "After: ";
		PmergeMe::printDeque(containers.getDeq());
		deque_time = static_cast<double>(deque_end - deque_start) * 1000 / CLOCKS_PER_SEC;
		std::cout << "Time taken: " << deque_time << "ms" << std::endl;
		containers.sortDeq();

	}
	catch (const std::exception& e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}