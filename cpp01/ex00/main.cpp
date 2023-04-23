#include "Zombie.hpp"

int main(void) {
	Zombie zInstance("Intance");

	zInstance.randomChump("ZombieRC1");
	Zombie* z = zInstance.newZombie("ZombieNew1");
	z->announce();
	delete z;
}