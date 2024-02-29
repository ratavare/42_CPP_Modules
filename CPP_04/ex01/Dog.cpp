#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	Animal::type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
	// *this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Ãooo" << std::endl;
}

void Dog::setIdea(std::string str) {
	this->brain->setIdea(str);
}

std::string Dog::getIdea(int ideanbr) const {
	return (this->brain->getIdea(ideanbr));
}