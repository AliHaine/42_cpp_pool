#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "Object Zombie " << this->name << " created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Object Zombie " << this->name << " destroyed" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "Object Zombie " << this->name << " created" << std::endl;
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
