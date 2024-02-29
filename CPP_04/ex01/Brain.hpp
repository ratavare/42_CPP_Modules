#pragma once

#include <iostream>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(Brain& copy);
	~Brain();
	Brain& operator=(Brain& copy);
	void setIdea(std::string str);
	std::string getIdea(int ideanbr) const;
};
