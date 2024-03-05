#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		const_cast<std::string&>(this->name) = copy.name;
		this->grade = copy.grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const {return (this->name);}

int Bureaucrat::getGrade(void) const {return (this->grade);}

void Bureaucrat::incrementGrade(void) {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", " << "bureaucrat grade " << obj.getGrade();
	return (os);
}