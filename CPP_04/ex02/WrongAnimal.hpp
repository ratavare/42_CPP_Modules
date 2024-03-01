#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& copy);
	
	std::string getType() const;
	virtual void makeSound() const;
};
