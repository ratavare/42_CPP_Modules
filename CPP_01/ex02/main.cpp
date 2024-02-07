#include <iostream>

int main()
{
	// Creating variables.
	std::string		str = "HI THIS IS BRAIN";
	std::string*	str_ptr;
		// References have to be assigned to initialized variables.
	std::string&	str_ref = str;

	//Assigning the pointer to the str variable.
	str_ptr = &str;

	std::cout << &str << std::endl;
	std::cout << str_ptr << std::endl;
	std::cout << &str_ref << std::endl;

	std::cout << std::endl;

	std::cout << str << std::endl;
	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;
}