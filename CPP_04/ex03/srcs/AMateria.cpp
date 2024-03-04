#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

AMateria::AMateria(const AMateria& copy) {
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else if (this->type == "ice")
		std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}