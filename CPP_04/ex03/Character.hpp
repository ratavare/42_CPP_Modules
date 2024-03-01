#pragma once

#include "lCharacter.hpp"

class Character : public ICharacter
{
public:
	Character() {}
	Character(const Character& copy);
	Character& operator=(const Character& copy);
	~Character() {}
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};