#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Default_ScavTrap") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other) {
    std::cout << "ScavTrap " << name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << name << " assigned." << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
    }
}