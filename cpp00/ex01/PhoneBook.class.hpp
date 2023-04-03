

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {
public:
	PhoneBook();
	Contact		CreateContact();
	Contact*	getContactList();
	int			getContactNb();
	void		IncreaseContactNb();
	int			getLastErase();
	void		setLastErase(int);
	std::string	ConvertStringToColumn(std::string);
	void		PrintColumnContact();
	void		PrintContactInfos(Contact);
	~PhoneBook();
private:
	Contact contact[8];
	int		nb_contacts;
	int		last_erase;
};

#endif
