#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "Animal copy called" << std::endl;
	this->type = animal.type;
}

Animal &Animal::operator=(const Animal &animal) {
	std::cout << "Animal copy assign called" << std::endl;
	this->type = animal.type;
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}
