#include "zombie.hpp"

Zombie::Zombie(){
    std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName) {
    this->name = newName;
}