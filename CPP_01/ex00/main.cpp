#include "Zombie.hpp"

int main() 
{
	Zombie um("ernesto");
	um.announce();

	Zombie* dois;
	dois = newZombie("joao");
	dois->announce();
	delete dois;

	randomChump("tereso");
}