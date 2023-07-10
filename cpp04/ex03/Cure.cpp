#include "Cure.hpp"

Cure::Cure(void) {
	std::cout << "Cure default constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure& cure) {
	std::cout << "Cure Copy constructor called" << std::endl;
	this->type = cure.type;
}

Cure& Cure::operator=(const Cure& cure) {
	std::cout << "Cure Copy assign constructor called" << std::endl;
	this->type = cure.type;
	return *this;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone(void) const {
	std::cout << "Cure clone func called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
