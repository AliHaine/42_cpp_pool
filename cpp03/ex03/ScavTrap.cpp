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

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
    std::cout << "Copy ScavTrap " << this->name << " constructor" << std::endl;
    this->name = scavTrap.name;
    this->healthPoints = scavTrap.healthPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->damagePoints = scavTrap.damagePoints;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& scavTrap) {
    std::cout << "Copy assignment operator called ScavTrap" << std::endl;
    this->name = scavTrap.name;
    this->healthPoints = scavTrap.healthPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->damagePoints = scavTrap.damagePoints;
    return (*this);
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints == 0) {
        this->noEnoughEnergy();
        return;
    }
    this->energyPoints--;
    std::cout << "Trap " << this->name << " attacks " << target << " with ScavTrap attack ability, causing " << this->damagePoints << " points of damage" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap entre en mode Gate keeper" << std::endl;
}
