#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Welcome to your awesome PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << '\r' << "BYE! HAVE A BEAUTIFUL TIME!" << std::endl;
}

void	PhoneBook::addContact() {
	int	i = 0;
	std::string	str;

	while (i < 8 && contact[i].getFilled() == true)
		i++;
	contact[i].addFirstName();
	contact[i].addLastName();
	contact[i].addPhoneNumber();
	contact[i].addNickname();
	contact[i].addDarkSecret();
	contact[i].setFilled(true);
	std::cout << "Done!" << std::endl;
}

void	PhoneBook::search() {
	std::string	input;

	if (contact[0].getFilled() == false)
		return (void)(std::cout << "You have no contacts" << std::endl);
	printContacts();
	std::cout << "Enter contact index: ";
	std::getline(std::cin, input);
	if (contact[atoi(input.c_str()) - 1].getFilled() == true)
		std::cout << "Contact exists" << std::endl;
}

void	PhoneBook::printContacts() {
	std::cout << std::setw(10) << std::right << "Index" << " | "
		<< std::setw(10) << std::right << "Fisrt name" << " | "
		<< std::setw(10) << std::right << "Last name" << " | "
		<< std::setw(10) << std::right << "Nickname" << std::endl;
	int	i = 0;
	while (i < 8 && contact[i].getFilled() == true) {
		std::cout << std::setw(10) << std::right << (i + 1) << " | "
			<< std::setw(10) << std::right << checkWord(contact[i].getFirstName()) << " | "
			<< std::setw(10) << std::right << checkWord(contact[i].getLastName()) << " | "
			<< std::setw(10) << std::right << checkWord(contact[i].getNickname()) << std::endl;
		i++;
	}
}

std::string PhoneBook::checkWord(std::string str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}


