#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>
class Zombie {
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(std::string newName);
};

Zombie* zombieHorde(int N, std::string name);

#endif
