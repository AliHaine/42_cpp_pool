#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) {
	this->setName(humanName);
	this->weapon = NULL;
	std::cout << "Object HumanB " << this->name << " created" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "Object HumanB " << this->name << " destroyed" << std::endl;
}

void HumanB::setName(std::string humanName) {
	this->name = humanName;
}

void HumanB::setWeapon(Weapon* weapon) {
	this->weapon = weapon;
}

std::string HumanB::getName(void) {
	return this->name;
}

Weapon* HumanB::getWeapon() {
	return this->weapon;
}

void HumanB::attack(void) {
	if (!this->weapon) {
		std::cout << this->name << " can't attack because he don't have any weapon " << std::endl;
		return;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}