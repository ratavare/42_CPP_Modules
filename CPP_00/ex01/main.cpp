#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "Enter a command. (ADD, SEARCH, EXIT)" << std::endl;
	while (true) {
		if (!std::cin)
			break ;
		std::cout << "Phonebook: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		if (input == "ADD")
			phoneBook.addContact();
		if (input == "SEARCH")
			phoneBook.search();
		else if (input[0] != '\0' && input != "ADD" && input != "SEARCH")
			std::cout << "Invalid command, try a valid one! (ADD, SEARCH, EXIT)" << std::endl;
	}
}