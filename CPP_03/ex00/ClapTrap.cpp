#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackdamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap named constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackdamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackdamage = copy.attackdamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points." << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " already fainted and can't attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing it to lose "
		<< this->attackdamage << " hit points." << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " already fainted." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage";
	this->hitPoints -= amount;
	if (this->hitPoints <= 0) {
		std::cout << " and died!" << std::endl;
		this->hitPoints = 0;
		return ;
	}
	std::cout << "!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points." << std::endl;
		return ;
	}
	else if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " already fainted and can't be repaired." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " repairs itself recovering "
		<< amount << " hit points." << std::endl;
	this->energyPoints--;
	this->hitPoints += amount;
}