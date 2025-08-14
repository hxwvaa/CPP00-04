#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "Weapon created: " << _type << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Weapon destroyed: " << _type << std::endl;
}

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type) {
    _type = type;
}