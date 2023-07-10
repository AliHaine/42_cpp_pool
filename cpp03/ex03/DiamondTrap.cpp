#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name") {
    this->name = "Default";
	this->healthPoints = FragTrap::_sHealthPoints;
	this->energyPoints = ScavTrap::_sEnergyPoints;
	this->damagePoints = FragTrap::_sAttackDamages;
	std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name") {
    this->name = name;
	this->healthPoints = FragTrap::_sHealthPoints;
	this->energyPoints = ScavTrap::_sEnergyPoints;
	this->damagePoints = FragTrap::_sAttackDamages;
	std::cout << "Object DiamondTrap " << this->name << " created" << std::endl;
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
    this->healthPoints = FragTrap::_sHealthPoints;
    this->energyPoints = ScavTrap::_sEnergyPoints;
    this->damagePoints = FragTrap::_sAttackDamages;
    return (*this);
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << this->name << " " << ClapTrap::name << std::endl;
}