#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

int main() 
{
	Zombie um("ernesto");
	um.announce();

	Zombie* dois;
	dois = newZombie("joao");
	delete dois;

	randomChump("tereso");
}