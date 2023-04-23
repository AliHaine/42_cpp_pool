#include "Zombie.hpp"

Zombie* Zombie::ZombieHorde(int n, std::string name) {
	Zombie* z = new Zombie[n];
	while (n > 0) {
		z[n-1] = *(newZombie(name));
		n--;
	}
	return z;
}