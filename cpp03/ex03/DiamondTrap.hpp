#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(void);
    DiamondTrap(const std::string name);
    ~DiamondTrap(void);
    DiamondTrap(const DiamondTrap& diamondTrap);
    DiamondTrap& operator=(const DiamondTrap& diamondTrap);
    void attack(const std::string& target);
    void whoAmI(void);
private:
    std::string name;
};


#endif
