#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name") {
    std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
    this->name = "Default";
    this->healthPoints = FragTrap::healthPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->damagePoints = FragTrap::damagePoints;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name") {
    std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
    this->name = name;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Object DiamondTrap " << this->name << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap) {
    std::cout << "Copy DiamondTrap " << this->name << " constructor" << std::endl;
    this->name = diamondTrap.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
    std::cout << "Copy assignment operator called DiamondTrap" << std::endl;
    this->name = diamondTrap.name;
    this->healthPoints = FragTrap::healthPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->damagePoints = FragTrap::damagePoints;
    return (*this);
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << this->name << " " << ClapTrap::name << std::endl;
}