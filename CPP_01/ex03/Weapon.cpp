#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) {
	std::cout << "Weapon constructor called" << std::endl;
	this->type = new_type;
}

Weapon::~Weapon() {
	std::cout << "Weapon destructor called" << std::endl;
}

const std::string&	Weapon::getType() {
	return (this->type);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}