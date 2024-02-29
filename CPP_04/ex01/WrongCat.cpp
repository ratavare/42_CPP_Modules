#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	this->type = copy.type;
	return (*this);
}

WrongCat::~WrongCat() {
		std::cout << "WrongCat default destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Oooof (?)" << std::endl;
}
