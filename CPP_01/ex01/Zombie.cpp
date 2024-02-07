#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie was constructed." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " was destructed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string str) {
	this->name = str;
}