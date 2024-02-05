#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "     _____                                                                    " << std::endl;
	std::cout << "  __|__   |__  __   _  _____  ____   _  ______  ______  _____  _____  __  __  " << std::endl;
	std::cout << " |     |     ||  |_| |/     \\|    \\ | ||   ___||      >/     \\/     \\|  |/ /  " << std::endl;
	std::cout << " |    _|     ||   _  ||  O  ||     \\| ||   ___||     < |  O  ||  O  ||     \\  " << std::endl;
	std::cout << " |___|     __||__| |_|\\_____/|__/\\____||______||______>\\_____/\\_____/|__|\\__\\ " << std::endl;
	std::cout << "    |_____|                                                                   " << std::endl << std::endl;

	std::cout << "Enter a command. (ADD, SEARCH, EXIT)" << std::endl;
	while (true) {
		std::cout << "Phonebook: ";
		std::getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
			break ;
		if (input == "ADD")
			phoneBook.addContact();
		if (input == "SEARCH")
			phoneBook.search();
		if (input[0] != '\0' && input != "ADD" && input != "SEARCH")
			std::cout << "Invalid command, try a valid one! (ADD, SEARCH, EXIT)" << std::endl;
	}
}
