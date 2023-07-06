#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	ClapTrap ct1 = ClapTrap("Bonjour");
    ScavTrap s1 = ScavTrap("test99");
	FragTrap f1 = FragTrap("frag1");

	ct1.attack("marwen");
	ct1.beRepaired(150);

	s1.guardGate();

	f1.highFivesGuys();

}
