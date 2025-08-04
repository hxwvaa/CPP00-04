#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("Me");
    ClapTrap claptrap2("You");

    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(3);
    
    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(10);
    
    claptrap1.beRepaired(5);
    
    return 0;
}