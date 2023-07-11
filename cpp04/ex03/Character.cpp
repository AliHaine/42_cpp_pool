#include "Character.hpp"

Character::Character(void) {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name) {
    std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(const Character& character) {
	std::cout << "Character copy constructor called" << std::endl;
    this->_name = character._name;
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i])
            break;
        delete this->_inventory[i];
    }
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = character._inventory[i];
}

Character& Character::operator=(const Character& character) {
	std::cout << "Character copy assign constructor called" << std::endl;
    this->_name = character._name;

    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i])
            break;
        delete this->_inventory[i];
    }
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = character._inventory[i];
    return *this;

}

Character::~Character(void) {
    std::cout << "Character default destructor called" << std::endl;
}

const std::string& Character::getName(void) const {
    return this->_name;
}

void Character::equip(AMateria *aMateria) {
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = aMateria;
			std::cout << "Character equip " << aMateria->getType() << " at slot" << i << std::endl;
            break;
        }
    }
	std::cout << "Characteer equip no available slot found" << std::endl;
}

void Character::unequip(int idx) {
	int i;

	if (idx >= 4) {
		std::cout << "Unequip index in more than 3" << std::endl;
		return;
	}
	if (!this->_inventory[idx]) {
		std::cout << "Unequip no item found at the slot " << idx << std::endl;
		return;
	}
	std::cout << "Unequip item at the slot " << idx << std::endl;
	i = idx;
	this->_inventory[idx] = 0;
	while (i < 3) {
		if (!this->_inventory[i + 1])
			return;
		this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[i + 1] = 0;
		i++;
	}


}

void Character::use(int idx, ICharacter& target) {

    if (idx >= 4) {
		std::cout << "Use index in more than 3" << std::endl;
		return;
	}
    if (!this->_inventory[idx]) {
		std::cout << "Use no item found at the slot " << idx << std::endl;
		return;
	}
	std::cout << "Use item at the slot " << idx << std::endl;
    this->_inventory[idx]->use(target);
}