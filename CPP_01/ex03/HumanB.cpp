#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : weapon(NULL) {
	std::cout << "HumanB constructor called" << std::endl;
	this->name = new_name;
}

HumanB::~HumanB() {
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::attack() {
	if (!this->weapon)
		std::cout << "Jim doesn't attack, he doesn't have a weapon" << std::endl;
	else {
	std::cout << this->name << " attacks with their "
		<< this->weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	this->weapon = &new_weapon;
}