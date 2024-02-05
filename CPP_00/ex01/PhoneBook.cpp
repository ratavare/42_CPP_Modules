#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Welcome to your awesome PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook() {
	// std::cout << '\r' << "BYE! HAVE A BEAUTIFUL TIME!" << std::endl;

	std::cout << std::endl << " _____   _____   _____   _____ " << std::endl;
	std::cout << "| _ ) \\ / / __| | _ ) \\ / / __|" << std::endl;
	std::cout << "| _ \\\\ V /| _|  | _ \\\\ V /| _| " << std::endl;
	std::cout << "|___/ |_| |___| |___/ |_| |___|" << std::endl << std::endl;
}

void	PhoneBook::addContact() {
	int	i = 0;
	static int contact_nbr;

	std::string	str;

	while (i < 8 && contact[i].getFilled() == true)
		i++;
	if (contact_nbr >= 8)
		i = contact_nbr % 8;
	contact[i].addFirstName();
	contact[i].addLastName();
	contact[i].addPhoneNumber();
	contact[i].addNickname();
	contact[i].addDarkSecret();
	contact[i].setFilled(true);
	contact_nbr++;
	if (!std::cin.eof())
		return ;
	std::cout << "Contact added!" << std::endl;
}

void	PhoneBook::search() {
	std::string	input;
	int			index;

	if (contact[0].getFilled() == false)
		return (void)(std::cout << "You have no contacts." << std::endl);
	printContacts();
	std::cout << "Enter contact index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	index = atoi(input.c_str()) - 1;
	if (index >= 0 && contact[index].getFilled() == true) {
		std::cout << std::endl <<  "First name: " << contact[index].getFirstName() << std::endl
			<< "Last name: " << contact[index].getLastName() << std::endl
			<< "Phone number: " << contact[index].getPhoneNumber() << std::endl
			<< "Nickname: " << contact[index].getNickname() << std::endl
			<< "Darkest secret: " << contact[index].getDarkSecret() << std::endl << std::endl;
	}
	else
		std::cout << "Contact does not exist." << std::endl;
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


