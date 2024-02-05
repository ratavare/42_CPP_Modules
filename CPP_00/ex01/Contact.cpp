#include "Contact.hpp"

Contact::Contact() {
	this->filled = false;
}

Contact::~Contact() {
}

bool	Contact::getFilled() {
	return (filled);
}

void	Contact::addFirstName() {
	std::string input;

	while (input.empty() && !std::cin.eof()) {
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	}
	this->first_name = input;
}

void	Contact::addLastName() {
	std::string input;

	while (input.empty() && !std::cin.eof()) {
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	}
	this->last_name = input;
}

void	Contact::addPhoneNumber() {
	std::string input;

	while (input.empty() && !std::cin.eof()) {
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	}
	this->phone_number = input;
}

void	Contact::addNickname() {
	std::string input;

	while (input.empty() && !std::cin.eof()) {
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	}
	this->nickname = input;
}

void	Contact::addDarkSecret() {
	std::string input;

	while ((input.empty() && !std::cin.eof())) {
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	}
	this->darkest_secret = input;
}

void	Contact::setFilled(bool val) {
	this->filled = val;
}

std::string	Contact::getFirstName() {
	return (this->first_name);
}

std::string	Contact::getLastName() {
	return (this->last_name);
}

std::string	Contact::getNickname() {
	return (this->nickname);
}

std::string	Contact::getPhoneNumber() {
	return (this->phone_number);
}

std::string	Contact::getDarkSecret() {
	return (this->darkest_secret);
}