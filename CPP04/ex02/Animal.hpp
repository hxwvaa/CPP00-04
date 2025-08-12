#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const = 0; // Pure virtual function
        const std::string &getType() const;
        void setType(const std::string &type);
};

#endif