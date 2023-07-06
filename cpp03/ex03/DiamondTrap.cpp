#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
    std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
    this->name = "Default";
    ClapTrap::name = this->name + "_clap_name";
    this->FragTrap::healthPoints = FragTrap::healthPoints;
    this->ScavTrap::energyPoints = ScavTrap::energyPoints;
    this->FragTrap::damagePoints = FragTrap::damagePoints;
}

DiamondTrap::DiamondTrap(const std::string name) : ScavTrap(name) {
    std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Object DiamondTrap " << this->name << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ScavTrap(diamondTrap) {
    std::cout << "Copy DiamondTrap " << this->name << " constructor" << std::endl;
    this->name = diamondTrap.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
    std::cout << "Copy assignment operator called DiamondTrap" << std::endl;
    this->name = diamondTrap.name;
    this->FragTrap::healthPoints = FragTrap::healthPoints;
    this->ScavTrap::energyPoints = ScavTrap::energyPoints;
    this->FragTrap::damagePoints = FragTrap::damagePoints;
    return (*this);
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << this->name << " " << ClapTrap::name << std::endl;
}