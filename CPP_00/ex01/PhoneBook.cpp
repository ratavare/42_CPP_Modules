#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor called" << std::endl;
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
}

void	PhoneBook::search() {
	printContacts();
}

void	PhoneBook::printContacts() {
	std::cout << std::setw(10) << std::right << "Index" << " | "
		<< std::setw(10) << std::right << "Fisrt name" << " | "
		<< std::setw(10) << std::right << "Last name" << " | "
		<< std::setw(10) << std::right << "Nickname" << std::endl;
	int	i = 0;
	while (i < 8 && contact[i].getFilled() == true) {
		std::cout << std::setw(10) << std::right << (i + 1) << " | ";
		i++;
	}
}
