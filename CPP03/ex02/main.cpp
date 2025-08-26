#include "FragTrap.hpp"

int main() {
    FragTrap fragtrap1("FragTrap1");
    FragTrap fragtrap2("FragTrap2");

    fragtrap1.attack(fragtrap2.getName());
    fragtrap2.takeDamage(5);
    fragtrap2.beRepaired(3);

    fragtrap1.attack(fragtrap2.getName());
    fragtrap2.takeDamage(10);

    fragtrap1.beRepaired(5);

    fragtrap1.highFivesGuys();

    return 0;
}