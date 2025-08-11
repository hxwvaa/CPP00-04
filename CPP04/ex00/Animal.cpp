#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assigned." << std::endl;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound." << std::endl;
}

const std::string &Animal::getType() const {
    return type;
}

void Animal::setType(const std::string &type) {
    this->type = type;
}
