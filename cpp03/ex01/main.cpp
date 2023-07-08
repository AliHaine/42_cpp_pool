#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap ct1 = ClapTrap("Bonjour");
    ScavTrap s1 = ScavTrap("test99");

	ct1.attack("marwen");
	ct1.beRepaired(150);

	s1.attack("tar");
	s1.guardGate();

}
