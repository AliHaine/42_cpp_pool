#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice& ice);
	Ice& operator=(const Ice& ice);
	~Ice(void);
	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif
