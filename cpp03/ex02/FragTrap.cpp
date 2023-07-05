#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default") {
	std::cout << "Object FragTrap " << this->name << " created" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "Object FragTrap " << this->name << " created" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "Object FragTrap " << this->name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Demande de high fives de FragTrap" << std::endl;
}
