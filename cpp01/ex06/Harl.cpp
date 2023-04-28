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

void Harl::complain(std::string level) {
	void (Harl::*pt[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::nothing};
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i].compare(level) == 0) {
			while (i < 4) {
				(this->*pt[i])();
				i++;
			}
			return;
		}
	}
	(this->*pt[4])();
}