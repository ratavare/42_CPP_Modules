#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy){
	if (this != &copy) {
		this->type = copy.type;
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Miauuu" << std::endl;
}

void Cat::setIdea(std::string str) {
	this->brain->setIdea(str);
}

std::string Cat::getIdea(int ideanbr) const {
	return (this->brain->getIdea(ideanbr));
}