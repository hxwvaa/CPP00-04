#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        delete brain; // Clean up existing brain
        brain = new Brain(*other.brain); // Deep copy the brain
        Animal::operator=(other);
        type = other.type;
    }
    std::cout << "Cat assigned." << std::endl;

    return *this;
}

Cat::~Cat() {
    delete brain;
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

Brain *Cat::getBrain() const {
    return brain;
}
