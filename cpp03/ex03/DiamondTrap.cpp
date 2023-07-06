#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default") {
    std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name) {
    std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Object DiamondTrap " << this->name << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
    std::cout << "Copy DiamondTrap " << this->name << " constructor" << std::endl;
    this->name = diamondTrap.name;
    this->healthPoints = diamondTrap.healthPoints;
    this->energyPoints = diamondTrap.energyPoints;
    this->damagePoints = diamondTrap.damagePoints;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
    std::cout << "Copy assignment operator called DiamondTrap" << std::endl;
    this->name = diamondTrap.name;
    this->healthPoints = diamondTrap.healthPoints;
    this->energyPoints = diamondTrap.energyPoints;
    this->damagePoints = diamondTrap.damagePoints;
    return (*this);
}