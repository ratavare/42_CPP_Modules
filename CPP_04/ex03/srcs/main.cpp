#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "===================================" << std::endl;

	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	ICharacter* antonio = new Character("antonio");
	ICharacter* ermelindo = new Character("ermelindo");
	AMateria* ice = src2->createMateria("ice");
	AMateria* cure = src2->createMateria("cure");
	// Equip and use materias
	antonio->equip(ice);
	antonio->equip(cure);
	antonio->use(0, *ermelindo);
	antonio->use(1, *ermelindo);
	antonio->use(2, *ermelindo);
	// Cloning
	ICharacter* antonietta = new Character(*static_cast<Character*>(antonio));
	antonietta->use(0, *ermelindo);
	antonietta->use(1, *ermelindo);
	antonietta->use(2, *ermelindo);
	std::cout << "============+++++++++++++===========" << std::endl;
	// Inventory limits & invalid operations
	for(int i = 0; i < 15; i++)
		antonietta->equip(src2->createMateria("cure"));
	antonietta->use(3, *ermelindo);
	antonietta->use(4, *ermelindo);
	for(int i = 0; i < 4; i++)
		antonietta->unequip(i);
	antonietta->use(0, *ermelindo);
	antonietta->use(1, *ermelindo);
	antonietta->use(2, *ermelindo);
	antonietta->use(3, *ermelindo);

	delete antonietta;
	delete ermelindo;
	delete antonio;
	delete src2;
}
