#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

AMateria::AMateria(const AMateria& copy) {
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {}