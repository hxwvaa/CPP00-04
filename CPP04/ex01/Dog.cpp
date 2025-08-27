#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created." << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        delete brain; // Clean up existing brain
        brain = new Brain(*other.brain); // Deep copy the brain
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Dog assigned." << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
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

Brain *Dog::getBrain() const {
    return brain;
}