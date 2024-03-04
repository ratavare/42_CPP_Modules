#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *slots[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& copy);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};