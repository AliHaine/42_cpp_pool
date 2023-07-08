#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongCat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = wrongCat.type;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat) {
	std::cout << "WrongCat copy assign constructor called" << std::endl;
	this->type = wrongCat.type;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "miaw miaw ฅ^•ﻌ•^ฅ" << std::endl;
}

std::string WrongCat::getType(void) const {
	return this->type;
}
