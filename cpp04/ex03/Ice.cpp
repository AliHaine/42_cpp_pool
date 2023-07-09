#include "Ice.hpp"

Ice::Ice(void) {
	std::cout << "Ice default constructor called" << std::endl
	this->type = "ice";
}

Ice::Ice(Ice& ice) {
	std::cout << "Ice Copy constructor called" << std::endl
	this->type = ice.type;
}

Ice& Ice::operator=(Ice& ice) {
	std::cout << "Ice Copy assign constructor called" << std::endl
	this->type = ice.type;
	return *this;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone(void) {

}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
