#include "Zombie.hpp"

Zombie::Zombie(void) {
	return;
}

Zombie::~Zombie(void) {
	std::cout << "Object " << this->name << " destroyed" << std::endl;
	return;
}

Zombie::Zombie(std::string name) {

	this->name = name;
}

void Zombie::announce() {
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() {
	return this->name;
}

Zombie* Zombie::newZombie(std::string name) {
	Zombie* z = new Zombie(name);
	return z;
}
