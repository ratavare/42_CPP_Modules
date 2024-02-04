#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

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
};

#endif