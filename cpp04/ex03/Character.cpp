#include "Character.hpp"

ICharacter::~ICharacter(void) {
	std::cout << "Icharacter default destructor called" << std::endl;
}

const std::string &ICharacter::getName() const {

}