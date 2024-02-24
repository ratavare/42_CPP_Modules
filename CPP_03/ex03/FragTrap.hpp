#pragma once

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap& operator=(const FragTrap& copy);
	FragTrap(const FragTrap& copy);

	void highFivesGuys(void);
};