#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) {
	std::cout << "WrongAnimal copy called" << std::endl;
	this->type = wrongAnimal.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& wrongAnimal) {
	std::cout << "WrongAnimal copy assign called" << std::endl;
	this->type = wrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Default WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}
