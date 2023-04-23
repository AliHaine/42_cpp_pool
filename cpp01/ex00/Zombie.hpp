#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
	Zombie(std::string);
	~Zombie(void);
	std::string getName(void) const;
	void announce(void);
	void randomChump(std::string);
	Zombie* newZombie(std::string);

private:
	std::string name;
};

#endif
