#include "ScavTrap.hpp"

void ScavTrap(const std::string name) : ClapTrap(name), energyPoints(10), healthPoints(10), damagePoints(0) {
    std::cout << "Object ScavTrap " << this->name << " created" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap entre en mode Gate keeper" << std::endl;
}
