//
// Created by Ali Yagmur on 3/31/23.
//

#include "global.hpp"

static void add_action(PhoneBook *pb) {
	try {
		pb->getContactList()[pb->getContactNb() % 8] = pb->CreateContact();
		pb->IncreaseContactNb();
	} catch (const std::runtime_error& e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

static void display_menu() {
	PhoneBook	pb;
	std::string	str;

	while (std::cin) {
		std::cout << "Select a command from the following list : ADD, SEARCH, EXIT." << std::endl;
		std::getline(std::cin, str);
		if (str == "EXIT")
			break;
		else if (str == "ADD") {
			add_action(&pb);
		} else if (str == "SEARCH") {
			if (pb.getContactNb() > 0)
				pb.PrintColumnContact();
			else
				std::cout << "You don't have any contact in your phonebook." << std::endl;
		} else
			std::cout << "Command unknow. Please try again." << std::endl;
	}
}

int main(void) {
	display_menu();

	return 0;
}