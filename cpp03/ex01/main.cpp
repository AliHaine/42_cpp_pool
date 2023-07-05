#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap ct1 = ClapTrap("Bonjour");
    ScavTrap("test");

	ct1.attack("marwen");
	ct1.beRepaired(150);

}
