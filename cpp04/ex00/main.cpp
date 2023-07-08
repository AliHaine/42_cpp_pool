#include "Animal.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	j->makeSound();
	j->makeSound();
	j->makeSound();
	j->makeSound();
	j->makeSound();
	j->makeSound();
	i->makeSound();
	i->makeSound();
	i->makeSound();
	i->makeSound();
	j->makeSound();
	i->makeSound();
	j->makeSound();
	i->makeSound();

	const Animal* wc = new Cat();
	wc->makeSound();
	delete wc;
	delete j;
	delete i;
	delete meta;
	return 0;
}
