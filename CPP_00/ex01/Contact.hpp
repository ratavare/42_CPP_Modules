#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	phone_number;
	std::string	nickname;
	std::string	darkest_secret;
	bool		filled;
public:
				Contact();
				~Contact();
	bool		getFilled();
	void		addFirstName();
	void		addLastName();
	void		addPhoneNumber();
	void		addNickname();
	void		addDarkSecret();
	void		setFilled(bool);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
};

#endif