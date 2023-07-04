#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap(const std::string);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	void noEnoughEnergy(void);

	std::string name;
	unsigned int healthPoints;
	unsigned int energyPoints;
	unsigned int damagePoints;
};

#endif