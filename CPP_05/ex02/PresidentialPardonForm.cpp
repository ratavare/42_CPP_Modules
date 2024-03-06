#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
AForm(copy) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy) {
		const_cast<std::string&>(this->target) = copy.target;
	}
}