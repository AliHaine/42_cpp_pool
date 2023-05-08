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

int	Contact::getIndex() const {
	return this->index;
}

std::string	Contact::getFirstName() const {
	return this->first_name;
}

std::string	Contact::getLastName() const {
	return this->last_name;
}

std::string	Contact::getNickName() const {
	return this->nick_name;
}

std::string	Contact::getPhoneNumber() const {
	return this->phone_number;
}

std::string	Contact::getDarkestSecret() const {
	return this->darkest_secret;
}

