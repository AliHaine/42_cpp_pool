#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string, Weapon);
	~HumanA(void);
	void attack(void);
	void setName(std::string);
	void setWeapon(Weapon);
	std::string getName(void);
	Weapon getWeapon(void);
private:
	Weapon weapon;
	std::string name;
};

#endif
