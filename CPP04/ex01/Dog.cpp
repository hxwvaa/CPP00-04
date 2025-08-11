#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    type = other.type;
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Dog assigned." << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

const std::string &Dog::getType() const {
    return type;
}

void Dog::setType(const std::string &type) {
    this->type = type;
}
