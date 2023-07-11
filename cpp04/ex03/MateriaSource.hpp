#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <list>

class MateriaSource : public IMateriaSource {
public:
    MateriaSource(void);
    MateriaSource(MateriaSource& materiaSource);
    MateriaSource& operator=(MateriaSource& materiaSource);
    ~MateriaSource(void);
    void learnMateria(AMateria* aMateria);
    AMateria* createMateria(const std::string& type);
	void addMatToList(AMateria* aMateria);
	void clearMatList(void);
private:
	std::list<AMateria*> itemsList;
    AMateria*	_matSrcInventory[4];
	int			_matNumber;
};

#endif
