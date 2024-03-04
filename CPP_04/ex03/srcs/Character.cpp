#include "Character.hpp"

Character::Character() {
	this->name = "Default";
	for (int i; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character& copy) {
	this->name = copy.name;
	for (int i = 0; i < 4; i++) {
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete inventory[i];
}

Character& Character::operator=(const Character& copy) {
	if (this == &copy)
		return *this;
	this->name = copy.name;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = copy.inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			break ;
		}
	}
}

// HANDLE LEAKS

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
	}
}
