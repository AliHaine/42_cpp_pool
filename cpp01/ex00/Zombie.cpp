#include "Zombie.hpp"

 Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "Object " << this->name << " destroyed" << std::endl;
	return;
}

std::string Zombie::getName(void) const {
	return this->name;
}

void Zombie::announce(void) {
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::randomChump(std::string name) {
	Zombie z(name);
	z.announce();
}

Zombie* Zombie::newZombie(std::string name) {
	Zombie* z = new Zombie(name);
	return z;
}