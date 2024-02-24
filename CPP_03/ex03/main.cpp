
#include "DiamondTrap.hpp"

int main (void)
{
	DiamondTrap trap("Roberto");

	trap.whoAmI();
	trap.attack("target");
	trap.guardGate();
	trap.highFivesGuys();
	trap.takeDamage(10);
	trap.beRepaired(10);
}