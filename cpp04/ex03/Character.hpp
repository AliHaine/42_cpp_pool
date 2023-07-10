#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character(void);
	Character(std::string name);
	Character(const Character& character);
	Character& operator=(const Character& character);
	~Character(void);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
    std::string _name;
    AMateria* _inventory[4];
};

#endif
