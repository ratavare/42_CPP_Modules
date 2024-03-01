#pragma once

#include <iostream>

class Animal
{
protected:
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal& copy);
	std::string type;
public:
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const = 0;
};