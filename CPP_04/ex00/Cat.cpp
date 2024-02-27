#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	this->type = copy.type;
	return (*this);
}

Cat::~Cat() {
		std::cout << "Cat default destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miauuu" << std::endl;
}
