#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++)
		this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy) {
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 4; i++) {
		delete this->slots[i];
		if (copy.slots[i])
			this->slots[i] = copy.slots[i];
		else
			this->slots[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->slots[i] != NULL)
			delete this->slots[i];
}

void MateriaSource::learnMateria(AMateria* mat) {
	for (int i = 0; i < 4; i++)
		if (!this->slots[i]) {
			this->slots[i] = mat;
			return ;
		}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] && this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	}
	return (0);
}