#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    type = other.type;
    std::cout << "WrongCat copied." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        type = other.type;
    }
    std::cout << "WrongCat assigned." << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat sound." << std::endl;
}

const std::string &WrongCat::getType() const {
    return type;
}

void WrongCat::setType(const std::string &type) {
    this->type = type;
}
