#include "Serialize.hpp"

Serialize::Serialize(void) {
	std::cout << "Serialize default constructor called" << std::endl;
}

Serialize::Serialize(Serialize &serialize) {
    (void)serialize;
	std::cout << "Serialize copy constructor called" << std::endl;
}

Serialize &Serialize::operator=(Serialize &serialize) {
    (void)serialize;
	std::cout << "Serialize copy assign constructor called" << std::endl;
	return *this;
}

Serialize::~Serialize(void) {
	std::cout << "Serialize destructor called" << std::endl;
}

uintptr_t Serialize::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialize::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}