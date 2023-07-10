#include "Character.hpp"

Character::Character(void) {
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : name(_name) {
    std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(Character& character) {
    this->_name = character._name;
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i])
            break;
        delete this->_inventory[i];
    }
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = character._inventory[i];
}

Character& Character::operator=(Character& character) {
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

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    //todo
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 4)
        return;
    if (!this->_inventory[idx])
        return;
    this->_inventory[idx]->use(target);
}