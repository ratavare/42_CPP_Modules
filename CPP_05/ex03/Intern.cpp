#include "Intern.hpp"

Intern::Intern() {
	formNames[0] = "ShrubberyForm";
	formNames[1] = "RobotomyForm";
	formNames[2] = "PresidentialPardonForm";
}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
	if (this != &copy) {
	for (int i = 0; i < 3; i++)
		this->formNames[i] = copy.formNames[i];
	}
	return (*this);
}

Intern::~Intern() {}

AForm* createPresidentialPardonForm(std::string target) {
        return new PresidentialPardonForm(target);
    }

AForm* createRobotomyRequestForm(std::string target) {
        return new RobotomyRequestForm(target);
    }

AForm* createShrubberyCreationForm(std::string target) {
        return new ShrubberyCreationForm(target);
    }

AForm* Intern::makeForm(std::string name, std::string target) {
	int i = 0;

	while (i < 3) {
		if (name == this->formNames[i])	
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Intern wasn't able to make form, exception: ";
			throw Intern::InexistentForm();
	}
}
