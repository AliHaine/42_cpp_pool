#include "Animal.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Cat a1 = Cat();
	Cat a2;

	a2 = a1;


	Animal* animal[50];

	for (int i = 0; i < 25; i++)
		animal[i] = new Dog();
	for (int i = 25; i < 50; i++)
		animal[i] = new Cat();
	for (int i = 0; i < 50; i++) {
		std::cout << "Animal " << i << " " << animal[i]->getType() << " ";
		animal[i]->makeSound();
	}
	for (int i = 0; i < 50; i++)
		delete animal[i];
	return 0;
}
