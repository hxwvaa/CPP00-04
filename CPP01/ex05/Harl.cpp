#include "Harl.hpp"

Harl::Harl() {
    std::cout << "Harl constructor called." << std::endl;
}

Harl::~Harl() {
    std::cout << "Harl destructor called." << std::endl;
}

void Harl::debug() {
    std::cout << "Debug: I love to get extra tomatoes for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
}

void Harl::info() {
    std::cout << "Info: I cannot believe adding extra tomatoes costs more money." << std::endl;
}

void Harl::warning() {
    std::cout << "Warning: I think I deserve to have some extra tomatoes for free." << std::endl;
}

void Harl::error() {
    std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    void (Harl::*funcs[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "Ye, don't come to me with that mate." << std::endl;
}
