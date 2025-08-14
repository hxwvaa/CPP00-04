#include "Zombie.hpp"

int main(){
    Zombie* heap = newZombie("heap_zombie");
    heap->announce();
    delete heap;
    randomChump("random_chump_zombie");
    Zombie stack("stack_zombie");
    stack.announce();
    return 0;
}