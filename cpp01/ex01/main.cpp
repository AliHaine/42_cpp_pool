#include "Zombie.hpp"

int main(void) {
	Zombie zInstance;
	Zombie* z = zInstance.ZombieHorde(10, "Le Z");
	for (int i = 0; i < 10; i++)
		std::cout << "Bonjour je suis " << z[i].getName() << std::endl;
	delete[] z;
	return (0);
}