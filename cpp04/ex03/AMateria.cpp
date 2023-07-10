#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& aMateria) {
	std::cout << "AMateria copy constructor called" << std::endl;
	this->type = aMateria.type;
}

AMateria &AMateria::operator=(const AMateria& aMateria) {
	std::cout << "AMateria copy assign constructor called" << std::endl;
	this->type = aMateria.type;
	return *this;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

std::string AMateria::getType(void) const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "Default AMateria use one " << target.getName() << std::endl;
}
