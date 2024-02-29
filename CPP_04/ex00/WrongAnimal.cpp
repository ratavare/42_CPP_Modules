#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "Zambugino";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	this->type = copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
		std::cout << "WrongAnimal default destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Nhaaahw" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}