#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_matSrcInventory = 0;
}

MateriaSource::MateriaSource(MateriaSource& materiaSource) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (!this->_matSrcInventory[i])
            break;
    }
    for (int i = 0; i < 4; i++)
        this->_matSrcInventory[i] = materiaSource._matSrcInventory[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource &materiaSource) {
    std::cout << "MateriaSource copy assign operator called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (!this->_matSrcInventory[i])
            break;
    }
    for (int i = 0; i < 4; i++)
        this->_matSrcInventory[i] = materiaSource._matSrcInventory[i];
    return *this;
}

MateriaSource::~MateriaSource(void) {
    std::cout << "MaterialSource default destructor called" << std::endl
}

void MateriaSource::learnMateria(AMateria* aMateria) {

}
