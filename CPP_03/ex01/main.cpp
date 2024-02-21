#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap clapTrap;
	ClapTrap clapTrap2("ClapTrap2");
	ClapTrap clapTrap3(clapTrap2);

	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);

	clapTrap2.attack("target");
	clapTrap2.takeDamage(5);
	clapTrap2.beRepaired(5);

	clapTrap3.attack("target");
	clapTrap3.takeDamage(5);
	clapTrap3.beRepaired(5);

	clapTrap2.takeDamage(100);
	clapTrap2.takeDamage(100);

	return (0);
}