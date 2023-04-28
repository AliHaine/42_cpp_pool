#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << "Object Harl created" << std::endl;
}

Harl::~Harl(void) {
	std::cout << "Object Harl destroyed" << std::endl;
}

void Harl::debug(void) {
	std::cout << "Debug func" << std::endl;
}

void Harl::info(void) {
	std::cout << "Info func" << std::endl;
}

void Harl::warning(void) {
	std::cout << "Warning func" << std::endl;
}

void Harl::error(void) {
	std::cout << "Error func" << std::endl;
}

void Harl::nothing(void) {
	std::cout << "Nothing func" << std::endl;
}

void Harl::complain(int level) {
	void (Harl::*pt[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::nothing};

	switch(level) {
		case 0:
			(this->*pt[0])();
		case 1:
			(this->*pt[1])();
		case 2:
			(this->*pt[2])();
		case 3:
			(this->*pt[3])();
			break;
		default:
			(this->*pt[4])();
			break;
	}
}