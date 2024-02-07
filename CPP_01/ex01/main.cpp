#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int		N = 5;
	Zombie	*Zombie = zombieHorde(N, "Antonio");
	
	for (int i = 0; i < N; i++)
		Zombie[i].announce();
	delete[] Zombie;
}