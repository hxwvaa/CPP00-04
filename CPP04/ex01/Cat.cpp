#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    type = other.type;
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Cat assigned." << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

const std::string &Cat::getType() const {
    return type;
}

void Cat::setType(const std::string &type) {
    this->type = type;
}
