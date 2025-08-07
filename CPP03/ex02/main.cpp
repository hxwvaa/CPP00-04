#include "FragTrap.hpp"

int main() {
    FragTrap fragtrap1("Me");
    FragTrap fragtrap2("You");

    fragtrap1.attack(fragtrap2.getName());
    fragtrap2.takeDamage(5);
    fragtrap2.beRepaired(3);

    fragtrap1.attack(fragtrap2.getName());
    fragtrap2.takeDamage(10);

    fragtrap1.beRepaired(5);

    fragtrap1.highFivesGuys();

    return 0;
}