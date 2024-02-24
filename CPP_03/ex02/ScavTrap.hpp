#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& copy);
	ScavTrap(const ScavTrap& copy);

	void attack(const std::string& target);
	void guardGate(void);
};
