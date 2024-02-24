#pragma once

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap& operator=(const FragTrap& copy);
	FragTrap(const FragTrap& copy);

	void attack(const std::string& target);
	void highFivesGuys(void);
};