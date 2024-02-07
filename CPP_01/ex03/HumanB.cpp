#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) {
	std::cout << "HumanB constructor called" << std::endl;
	this->name = new_name;
}

HumanB::~HumanB() {
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::attack() {
	std::cout << this->name << " attacks with their "
		<< this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	this->weapon = &new_weapon;
}