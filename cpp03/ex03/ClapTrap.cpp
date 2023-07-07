#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), healthPoints(10), energyPoints(10), damagePoints(0) {
    std::cout << "Object ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), healthPoints(10), energyPoints(10), damagePoints(0) {
    std::cout << "Object ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int healthPoints, unsigned int energyPoints, unsigned int damagePoints)
				: name(name), healthPoints(healthPoints), energyPoints(energyPoints), damagePoints(damagePoints) {
	std::cout << "Object ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Object ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
    std::cout << "Copy ClapTrap " << this->name << " constructor" << std::endl;
	this->name = clapTrap.name;
	this->healthPoints = clapTrap.healthPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->damagePoints = clapTrap.damagePoints;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap) {
    std::cout << "Copy assignment operator called ClapTrap" << std::endl;
    this->name = clapTrap.name;
	this->healthPoints = clapTrap.healthPoints;
    this->energyPoints = clapTrap.energyPoints;
    this->damagePoints = clapTrap.damagePoints;
    return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints == 0) {
		this->noEnoughEnergy();
		return;
	}
	this->energyPoints--;
	std::cout << "Trap " << this->name << " attacks " << target << " with ClapTrap attack ability, causing " << this->damagePoints << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->healthPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints == 0) {
		this->noEnoughEnergy();
		return;
	}
	this->energyPoints--;
	this->healthPoints += amount;
	std::cout << "ClapTrap " << this->name << " regenerate " << amount << " of health points and have now " << this->healthPoints << std::endl;
}

void ClapTrap::noEnoughEnergy(void) {
	std::cout << "ClapTrap " << this->name << " dont have enough energy for do that" << std::endl;

}