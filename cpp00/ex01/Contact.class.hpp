#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>

class Contact {
public:
	Contact();

	int			getIndex() const;
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

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
