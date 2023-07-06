#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP


class DiamondTrap : public ClapTrap, public ScavTrap {
public:
    DiamondTrap(void);
    DiamondTrap(const std::string name);
    ~DiamondTrap(void);
    DiamondTrap(DiamondTrap& diamondTrap);
    DiamondTrap operator=(DiamondTrap& diamondTrap);
    void whoAmI(void);
private:
    std::string name;
};


#endif
