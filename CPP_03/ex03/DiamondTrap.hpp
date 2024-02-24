#pragma once

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& copy);
	DiamondTrap(const DiamondTrap& copy);

	void whoAmI();
	void getStats();
};
