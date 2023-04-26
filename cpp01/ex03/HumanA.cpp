#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon weapon) : weapon(weapon) {
	this->setName(humanName);
	this->setWeapon(weapon);
	std::cout << "Object HumanA " << this->name << " created" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "Object HumanA " << this->name << " destroyed" << std::endl;
}

void HumanA::setName(std::string humanName) {
	this->name = humanName;
}

void HumanA::setWeapon(Weapon weapon) {
	this->weapon = weapon;
}

std::string HumanA::getName() {
	return this->name;
}

Weapon HumanA::getWeapon() {
	return this->weapon;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}