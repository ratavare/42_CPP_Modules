#include "Harl.hpp"

void (Harl::*Harl::functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::other( void ) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain( std::string level ) {
	std::string	strs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	j = 5;

	for (int i = 0; i < 4; i++) {
		if (level == strs[i])
			j = i + 1;
	}
	switch (j) {
	case 1:
		debug();
		// fall through
	case 2:
		info();
		// fall through
	case 3:
		warning();
		// fall through
	case 4:
		error();
		break ;
	default:
		other();
	}
}
