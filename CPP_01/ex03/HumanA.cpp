#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon& weapon_ptr) : weapon(weapon_ptr) {
	std::cout << "HumanA constructor called" << std::endl;
	this->name = new_name;
	this->weapon = weapon_ptr;
}

HumanA::~HumanA() {
	std::cout << "HumanA destructor called" << std::endl;
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their "
		<< weapon.getType() << std::endl;
}