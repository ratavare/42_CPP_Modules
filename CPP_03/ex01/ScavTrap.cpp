#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "Scavie";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->atackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap named constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->atackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->atackDamage = copy.atackDamage;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	*this = copy;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " has no will to attack." << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << this->name << " already died and can't attack." << std::endl;
		return ;
	}
	std::cout << this->name << " beats up " << target << " causing it to cry and lose "
		<< this->atackDamage << " hit points." << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate(void) {
	std::cout << this->name << " is now guarding some gate ... somewhere." << std::endl;
}