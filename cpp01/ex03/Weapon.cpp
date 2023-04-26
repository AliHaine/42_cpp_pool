#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName) {
	this->setType(weaponName);
	std::cout << "Object Weapon" << this->type << " created" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "Object Weapon" << this->type << " destroyed" << std::endl;
}

void Weapon::setType(std::string weaponName) {
	this->type = weaponName;
}

const std::string& Weapon::getType(void) const {
	return this->type;
}
