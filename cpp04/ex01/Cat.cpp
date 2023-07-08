#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = cat.type;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat copy assign constructor called" << std::endl;
	this->type = cat.type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "miaw miaw ฅ^•ﻌ•^ฅ" << std::endl;
}

std::string Cat::getType(void) const {
	return this->type;
}
