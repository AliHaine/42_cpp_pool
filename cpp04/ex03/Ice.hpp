#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(Ice& ice);
	Ice& operator=(Ice& ice);
	~Ice(void);
	AMateria* clone(void);
};

#endif
