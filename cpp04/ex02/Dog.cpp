#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = dog.type;
	this->brain = dog.brain;
}

Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog copy assign constructor called" << std::endl;
	this->type = dog.type;
	this->brain = dog.brain;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound(void) const {
	std::cout << "waf waf V•ᴥ•V" << std::endl;
}

std::string Dog::getType(void) const {
	return this->type;
}
