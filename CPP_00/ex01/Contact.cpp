#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact constructor called" << std::endl;
	this->filled = 0;
}

Contact::~Contact() {
	std::cout << "Contact destructor called" << std::endl;
}

bool	Contact::getFilled() {
	return (filled);
}

void	Contact::addFirstName() {
	std::string input;

	std::cout << "First Name: ";
	std::cin >> input;
	this->first_name = input;
}

void	Contact::addLastName() {
	std::string input;

	std::cout << "Last Name: ";
	std::cin >> input;
	this->last_name = input;
}

void	Contact::addPhoneNumber() {
	std::string input;

	std::cout << "Phone Number: ";
	std::cin >> input;
	this->phone_number = input;
}

void	Contact::addNickname() {
	std::string input;

	std::cout << "Nickname: ";
	std::cin >> input;
	this->nickname = input;
}

void	Contact::addDarkSecret() {
	std::string input;

	std::cout << "Darkest secret: ";
	std::cin >> input;
	this->darkest_secret = input;
}

void	Contact::setFilled(bool val) {
	this->filled = val;
}

std::string	getFirstName() {
	
}