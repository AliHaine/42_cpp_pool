#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) {
	std::cout << "Animal copy called" << std::endl;
	this->type = animal.type;
}

Animal &Animal::operator=(const Animal& animal) {
	std::cout << "Animal copy assign called" << std::endl;
	this->type = animal.type;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Default Animal sound" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}
