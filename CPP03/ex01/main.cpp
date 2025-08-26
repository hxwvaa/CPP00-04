#include "ScavTrap.hpp"

int main() {
    ScavTrap scavtrap1("ScavTrap1");
    ScavTrap scavtrap2("ScavTrap2");

    scavtrap1.attack(scavtrap2.getName());
    scavtrap2.takeDamage(5);
    scavtrap2.beRepaired(3);

    scavtrap1.attack(scavtrap2.getName());
    scavtrap2.takeDamage(10);

    scavtrap1.beRepaired(5);

    scavtrap1.guardGate();

    return 0;
}