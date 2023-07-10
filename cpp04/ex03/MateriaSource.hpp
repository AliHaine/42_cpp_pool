#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource(void);
    MateriaSource(MateriaSource& materiaSource);
    MateriaSource& operator=(MateriaSource& materiaSource);
    ~MateriaSource(void);
    void learnMateria(AMateria* aMateria);
    AMateria* createMateria(const std::string& type);
private:
    AMateria* _matSrcInventory[4];
};

#endif
