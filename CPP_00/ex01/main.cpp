# include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	while (true) {
		std::cin >> input;
		if (input == "EXIT")
			break ;
		if (input == "ADD")
			phoneBook.addContact();
		if (input == "SEARCH")
			phoneBook.search();
	}
}