#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& copy);
	~Animal();
	Animal& operator=(const Animal& copy);
	
	std::string getType() const;
	virtual void makeSound() const;
};
