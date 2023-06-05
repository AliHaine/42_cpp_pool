//
// Created by Ali Yagmur on 3/31/23.
//

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Initalization of Contact" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Object Contact destroyed" << std::endl;
	return;
}


void Contact::setIndex(int index) {
	if (index == 8)
		this->index = 1;
	else
		this->index = index + 1;
}

void Contact::setFirstName(const std::string& first_name) {
	this->first_name = first_name;
}
void Contact::setLastName(const std::string& last_name) {
	this->last_name = last_name;
}
void Contact::setNickName(const std::string& nick_name) {
	this->nick_name = nick_name;
}
void Contact::setPhoneNumber(const std::string& phone_number) {
	this->phone_number = phone_number;
}
void Contact::setDarkestSecret(const std::string& darkest_secret) {
	this->darkest_secret = darkest_secret;
}

int	Contact::getIndex(void) const {
	return this->index;
}

std::string	Contact::getFirstName(void) const {
	return this->first_name;
}

std::string	Contact::getLastName(void) const {
	return this->last_name;
}

std::string	Contact::getNickName(void) const {
	return this->nick_name;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->phone_number;
}

std::string	Contact::getDarkestSecret(void) const {
	return this->darkest_secret;
}

