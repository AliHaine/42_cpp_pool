#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
    ClapTrap(void);
    ClapTrap(const std::string name);
	ClapTrap(const std::string name, unsigned int healthPoints, unsigned int energyPoints, unsigned int damagePoints);
    ClapTrap(const ClapTrap& clapTrap);
    ~ClapTrap(void);
    ClapTrap& operator=(const ClapTrap& clapTrap);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	void noEnoughEnergy(void);

	std::string name;
	unsigned int healthPoints;
	unsigned int energyPoints;
	unsigned int damagePoints;
};

#endif