#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    std::cout << "HumanA constructor called with name: " << _name << " with weapon: " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << "HumanA destructor called for: " << _name << std::endl;
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}