#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(Brain& copy) {
	*this->ideas = *copy.ideas;
	return *this;
}

void Brain::setIdea(std::string str) {
	for (int i = 0; i < 100; i++)
		if (this->ideas[i].empty()) {
			this->ideas[i] = str;
			break ;
		}
}

std::string Brain::getIdea(int ideanbr) const {
	if (this->ideas[ideanbr].empty())
		return ("...no idea...\n");
	return (this->ideas[ideanbr]);
}