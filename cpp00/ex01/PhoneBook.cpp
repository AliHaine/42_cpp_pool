//
// Created by Ali Yagmur on 3/31/23.
//

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Initalization of PhoneBook" << std::endl;
	return;
}

Contact* PhoneBook::getContactList() {
	return this->contact;
}

int PhoneBook::getContactNb() {
	return this->nb_contacts;
}

void PhoneBook::IncreaseContactNb() {
	this->nb_contacts++;
}

int PhoneBook::getLastErase() {
	return this->last_erase;
}

void PhoneBook::setLastErase(int erase) {
	this->last_erase = erase;
}

std::string PhoneBook::ConvertStringToColumn(std::string str) {
	std::string copy = str;

	if (str.length() >= 10) {
		copy = copy.substr(0, 9);
		copy.push_back('.');
	} else {
		if (copy.length() < 10) {
			while (copy.length() < 10)
				copy.insert(0, 1, ' ');
		}
	}
	copy.push_back('|');
	return (copy);
}

Contact PhoneBook::CreateContact() {
	std::string str;
	Contact contact;

	std::cout << "Enter the first name :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty())
		throw std::runtime_error("The first name can't be empty.");
	contact.setFirstName(str);

	std::cout << "Enter the last name :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty())
		throw std::runtime_error("The last name can't be empty.");
	contact.setLastName(str);

	std::cout << "Enter the nick name :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty())
		throw std::runtime_error("The nick name can't be empty.");
	contact.setNickName(str);

	std::cout << "Enter the phone number :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty())
		throw std::runtime_error("The phone number can't be empty.");
	contact.setPhoneNumber(str);

	std::cout << "Enter the darkest secret :" << std::endl;
	std::getline(std::cin, str);
	if (str.empty())
		throw std::runtime_error("the darkest secret can't be empty");
	contact.setDarkestSecret(str);
	contact.setIndex(getContactNb());
	std::cout << "Successful, you have created a new contact." << std::endl;
	return (contact);
}

void PhoneBook::PrintColumnContact() {
	int			size = -1;
	std::string	str;
	int			max = getContactNb();
	if (max > 8)
		max = 8;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     index|first_name| last_name|  nickname|" << std::endl;
	while (size++ < max - 1) {
		std::cout << "|" << ConvertStringToColumn(std::to_string(contact[size].getIndex())) << ConvertStringToColumn(contact[size].getFirstName()) << ConvertStringToColumn(contact[size].getLastName()) << ConvertStringToColumn(contact[size].getNickName()) << std::endl;
	}
	try {
		std::cout << "|-------------------------------------------|" << std::endl << "Please enter the wanted index: ";
		std::getline(std::cin, str);
		size = std::stoi(str);
	} catch (const std::exception err) {
		std::cout << "Number exception" << std::endl;
		return;
	}
	if (size > 8 || size > max || size == 0)
	{
		std::cout << "You don't have any contact with this index." << std::endl;
		return;
	}
	PrintContactInfos(contact[size - 1]);
}

void PhoneBook::PrintContactInfos(Contact contact) {
	std::cout << "First name: " + contact.getFirstName() << std::endl << "Lastname: " + contact.getLastName() << std::endl << "Nickname: " + contact.getNickName() << std::endl << "PhoneNumber: " + contact.getPhoneNumber() << std::endl <<  "Darkest secret: " + contact.getDarkestSecret() << std::endl;
}

PhoneBook::~PhoneBook(void) {}