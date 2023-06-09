#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const std::string name);
	~ScavTrap(void);
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    void attack(const std::string& target);
    void guardGate(void);
	static unsigned int _sEnergyPoints;
};

#endif
