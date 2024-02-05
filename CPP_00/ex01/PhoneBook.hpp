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
	std::string	checkWord(std::string str);
	void	printContacts();
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	search();
};

#endif