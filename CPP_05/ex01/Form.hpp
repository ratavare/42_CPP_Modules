#pragma once

#include <iostream>

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			executeGrade;

	Form();

public:
	~Form();
};
