#include "Cure.hpp"

Cure::Cure() : AMateria() {
	this->type = "cure";
}

Cure::Cure(const Cure& copy) : AMateria(copy) {
	*this = copy;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& copy) {
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

AMateria* Cure::clone() const {
	return (new Cure);
}

