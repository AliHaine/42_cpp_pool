#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string);
	~HumanB(void);
	void attack(void);
	void setName(std::string);
	void setWeapon(Weapon);
	std::string getName(void);
	Weapon* getWeapon(void);
private:
	Weapon* weapon;
	std::string name;
};

#endif
