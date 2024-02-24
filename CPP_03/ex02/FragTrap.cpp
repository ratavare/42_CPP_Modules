#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "Fraggie";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackdamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap named constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackdamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	this->name = copy.name;
	this->attackdamage = copy.attackdamage;
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

void FragTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << this->name << " is way too tired to do anything!" << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << this->name << " R.I.P, can't do nothing." << std::endl;
		return ;
	}
	std::cout << this->name << " bombards " << target << " causing a *BOOM* and it lose "
		<< this->attackdamage << " hit points." << std::endl;
	this->energyPoints--;
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->name << " says: plz hi-5 me bro :(" << std::endl;
}