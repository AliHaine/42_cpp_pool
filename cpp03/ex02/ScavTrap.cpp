#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default") {
	std::cout << "Object ScavTrap " << this->name << " created" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "Object ScavTrap " << this->name << " created" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Object ScavTrap " << this->name << " destroyed" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap entre en mode Gate keeper" << std::endl;
}
