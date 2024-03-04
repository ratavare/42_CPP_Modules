#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& copy);
	~Ice();
	Ice& operator=(const Ice& copy);

	AMateria* clone() const;
};
