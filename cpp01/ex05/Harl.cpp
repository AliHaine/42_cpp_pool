#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << "Object Harl created" << std::endl;
}

Harl::~Harl(void) {
	std::cout << "Object Harl destroyed" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*pf[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*pf[i])();
			break;
		}
	}
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