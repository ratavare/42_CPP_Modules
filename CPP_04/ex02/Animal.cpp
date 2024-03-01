#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Gambuzino";
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy) {
	this->type = copy.type;
	return (*this);
}

Animal::~Animal() {
		std::cout << "Animal default destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Whaaahn" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}