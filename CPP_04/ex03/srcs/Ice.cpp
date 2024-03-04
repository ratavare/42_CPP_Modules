#include "Ice.hpp"

Ice::Ice() : AMateria() {
	this->type = "ice";
}

Ice::Ice(const Ice& copy) : AMateria(copy) {
	*this = copy;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& copy) {
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

AMateria* Ice::clone() const {
	return (new Ice);
}

