#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j; //should not create a leak
delete i;

std::cout << std::endl << "==================================" << std::endl << std::endl;

Animal *petArray[10];
for (int i = 0; i < 10; i++) {
	if (i < 5)
		petArray[i] = new Dog();
	else
		petArray[i] = new Cat();
	petArray[i]->makeSound();
}
for (int i = 0; i < 10; i++)
	delete petArray[i];

std::cout << std::endl << "==================================" << std::endl << std::endl;

Dog bobi;
bobi.setIdea("Sou um dog com 30 anos\n");
std::cout << bobi.getIdea(0);
bobi.setIdea("Nao curto desses gatos\n");
std::cout << bobi.getIdea(1);
std::cout << bobi.getIdea(2); // no idea.

Dog fakeBobi(bobi);
std::cout << fakeBobi.getType() << std::endl;
std::cout << fakeBobi.getIdea(0);
std::cout << fakeBobi.getIdea(1);
return 0;
}