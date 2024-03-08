#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Intern johnny;
		AForm* doc1 = johnny.makeForm("RobotomyForm", "Malandro");
		Bureaucrat tim("Tim", 1);
		std::cout << tim << std::endl;
		tim.signForm(*doc1);
		tim.executeForm(*doc1);
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}