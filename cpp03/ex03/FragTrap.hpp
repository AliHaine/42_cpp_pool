#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string name);
	~FragTrap(void);
    FragTrap(const FragTrap& fragTrap);
    FragTrap& operator=(const FragTrap& fragTrap);
	void highFivesGuys(void);
};

#endif
