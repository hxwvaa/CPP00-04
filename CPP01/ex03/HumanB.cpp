#include "HumanB.hpp"

HumanB::HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
    std::cout << "HumanB constructor called with name: " << _name << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB destructor called for: " << _name << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
    std::cout << _name << " has set their weapon to: " << _weapon->getType() << std::endl;
}

void HumanB::attack() {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}