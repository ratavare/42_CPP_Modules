#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ScavTrap::energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
	this->name = name;
	ScavTrap::energyPoints = 50;
	ClapTrap::name = name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackdamage = copy.attackdamage;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	*this = copy;
}

void DiamondTrap::whoAmI() {
	std::cout << this->name << std::endl;
	std::cout << ClapTrap::name << std::endl;
}