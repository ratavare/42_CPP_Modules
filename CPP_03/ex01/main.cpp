
#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap scav("GoodScav");
	ScavTrap scav2("EvilScav");
	ScavTrap scav3;


	scav = scav2;
	scav3 = scav;
	scav.attack("target");
	scav2.attack("target2");
	scav3.attack("target3");

	scav.takeDamage(5);

	scav.beRepaired(5);

	scav.attack("target");
	scav.attack("target2");
	scav.guardGate();


	return (0);
}