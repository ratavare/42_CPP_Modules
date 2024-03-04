#include "Character.hpp"
#include <cstdio>

Character::Character() {
	this->name = "Default";
	this->droppedIndex = 0;
	for (int i; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	this->name = name;
	this->droppedIndex = 0;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character& copy) {
	this->name = copy.name;
	this->droppedIndex = copy.droppedIndex;
	for (int i = 0; i < 4; i++) {
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete inventory[i];
	if (this->droppedIndex > 0)
	while (this->droppedIndex > 0)
    	delete this->dropped[--droppedIndex];
}


Character& Character::operator=(const Character& copy) {
	if (this == &copy)
		return *this;
	this->name = copy.name;
	this->droppedIndex = copy.droppedIndex;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
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
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->dropped[this->droppedIndex] = this->inventory[idx];
		this->inventory[idx] = NULL;
		this->droppedIndex++;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		this->inventory[idx]->use(target);
	}
}
