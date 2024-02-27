#include <iostream>

int main()
{
	// Creating variables.
	std::string		str = "HI THIS IS BRAIN";
	std::string*	strPTR;

	// References have to be assigned to initialized variables.
	std::string&	strREF = str;

	//Assigning the pointer to the str variable.
	strPTR = &str;

	std::cout << &str << std::endl;
	std::cout << strPTR << std::endl;
	std::cout << &strREF << std::endl;

	std::cout << std::endl;

	std::cout << str << std::endl;
	std::cout << *strPTR << std::endl;
	std::cout << strREF << std::endl;
}