#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>

class Contact {
public:
	Contact(void);
	~Contact(void);
	int			getIndex(void) const;
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

	void setIndex(int index);
	void setFirstName(const std::string& first_name);
	void setLastName(const std::string& last_name);
	void setNickName(const std::string& nick_name);
	void setPhoneNumber(const std::string& phone_number);
	void setDarkestSecret(const std::string& darkest_secret);
private:
	int			index;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
};

#endif
