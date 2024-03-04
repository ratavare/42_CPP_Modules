#pragma once

#include <iostream>
#include "Character.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;

	AMateria();
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& copy);
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};