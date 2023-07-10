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
	while (this->_matNumber-- > 0)
		delete this->_matSrcInventory[_matNumber];
}

void MateriaSource::learnMateria(AMateria* aMateria) {
	if (this->_matNumber >= 4) {
		std::cout << "MaterialSource inventory is already full" << std::endl;
		return;
	}
	this->_matSrcInventory[this->_matNumber] = aMateria;
	std::cout << "AMateria " << aMateria->getType() << " stocked at slot number " << this->_matNumber << std::endl;
	this->_matNumber++;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (this->_matSrcInventory[i] && this->_matSrcInventory[i]->getType() == type) {
			std::cout << "Materia with type " << type << " found at slot " << i << std::endl;
			return this->_matSrcInventory[i]->clone();
		}
	}
	std::cout << "no materia with type " << type << " found" << std::endl;
	return 0;
}
