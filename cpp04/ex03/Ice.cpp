#include "Ice.hpp"

Ice::Ice(void) {
	std::cout << "Ice default constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& ice) {
	std::cout << "Ice Copy constructor called" << std::endl;
	this->type = ice.type;
}

Ice& Ice::operator=(const Ice& ice) {
	std::cout << "Ice Copy assign constructor called" << std::endl;
	this->type = ice.type;
	return *this;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone(void) const {
	std::cout << "Ice clone func called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
