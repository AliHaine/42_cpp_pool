#include "Animal.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal animal[50];

	for (int i = 0; i < 25; i++)
		animal[i] = new Dog();
	for (int i = 0; i < 25; i++)
		animal[i] = new Cat();
	for (int i = 0; i < 50; i++)
		delete animal[i];
	return 0;
}
