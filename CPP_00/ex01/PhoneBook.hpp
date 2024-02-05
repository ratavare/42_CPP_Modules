#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <string>
# include <stdlib.h>

class PhoneBook
{
private:
	Contact contact[8];
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	search();
	void	printContacts();
	std::string	checkWord(std::string str);
};

#endif