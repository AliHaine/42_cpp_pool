#include "Serialize.hpp"

Serialize::Serialize(void) {
	std::cout << "Serialize default constructor called" << std::endl;
}

Serialize::Serialize(Serialize &serialize) {
	std::cout << "Serialize copy constructor called" << std::endl;
}

Serialize &Serialize::operator=(Serialize &serialize) {
	std::cout << "Serialize copy assign constructor called" << std::endl;
	return *this;
}

Serialize::~Serialize(void) {
	std::cout << "Serialize destructor called" << std::endl;

}