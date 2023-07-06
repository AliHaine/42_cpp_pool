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

FragTrap::FragTrap(const FragTrap& fragTrap) {
    std::cout << "Copy FragTrap " << this->name << " constructor" << std::endl;
    this->name = fragTrap.name;
    this->healthPoints = fragTrap.healthPoints;
    this->energyPoints = fragTrap.energyPoints;
    this->damagePoints = fragTrap.damagePoints;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
    std::cout << "Copy assignment operator called FragTrap" << std::endl;
    this->name = fragTrap.name;
    this->healthPoints = fragTrap.healthPoints;
    this->energyPoints = fragTrap.energyPoints;
    this->damagePoints = fragTrap.damagePoints;
    return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Demande de high fives de FragTrap" << std::endl;
}
