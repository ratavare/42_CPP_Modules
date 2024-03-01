#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	~Cat();

	void makeSound() const;
	void setIdea(std::string str);
	std::string getIdea(int ideanbr) const;
};
