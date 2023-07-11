#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _matNumber(0) {
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_matSrcInventory[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource& materiaSource) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = materiaSource._matNumber; i > 0; i--) {
		this->_matSrcInventory[i-1] = materiaSource._matSrcInventory[i-1];
	}
	this->_matNumber = materiaSource._matNumber;
}

MateriaSource &MateriaSource::operator=(MateriaSource& materiaSource) {
    std::cout << "MateriaSource copy assign operator called" << std::endl;
	for (int i = materiaSource._matNumber; i > 0; i--) {
		this->_matSrcInventory[i-1] = materiaSource._matSrcInventory[i-1];
	}
	this->_matNumber = materiaSource._matNumber;
    return *this;
}

MateriaSource::~MateriaSource(void) {
    std::cout << "MaterialSource default destructor called" << std::endl;
	clearMatList();
}

void MateriaSource::learnMateria(AMateria* aMateria) {
	if (this->_matNumber >= 4) {
		std::cout << "MaterialSource inventory is already full" << std::endl;
		return;
	}
	addMatToList(aMateria);
	this->_matSrcInventory[this->_matNumber] = aMateria;
	std::cout << "AMateria " << aMateria->getType() << " stocked at slot number " << this->_matNumber << std::endl;
	this->_matNumber++;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	AMateria* aMateria;

	for (int i = 0; i < 4; i++) {
		if (this->_matSrcInventory[i] && this->_matSrcInventory[i]->getType() == type) {
			std::cout << "Materia with type " << type << " found at slot " << i << std::endl;
			aMateria = this->_matSrcInventory[i]->clone();
			addMatToList(aMateria);
			return aMateria;
		}
	}
	std::cout << "no materia with type " << type << " found" << std::endl;
	return 0;
}

void MateriaSource::addMatToList(AMateria *aMateria) {
	this->itemsList.push_back(aMateria);
}

void MateriaSource::clearMatList(void) {
	std::list<AMateria*>::iterator it;

	for (it = this->itemsList.begin(); it != this->itemsList.end(); it++)
		delete *it;
}
