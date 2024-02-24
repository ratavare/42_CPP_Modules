
#include "FragTrap.hpp"

int main (void)
{
	FragTrap frag("Antonio");
	ClapTrap clap("Manel");
	ScavTrap scav;

	frag.attack("Manel");
	clap.takeDamage(30);
	clap.attack("Antonio");
	scav.attack("Antonio");
	scav.guardGate();
	frag.attack("Scavie");
	scav.takeDamage(29);
	scav.beRepaired(29);
	scav.attack("Antonio");
	frag.takeDamage(20);
	frag.highFivesGuys();

	return (0);
}