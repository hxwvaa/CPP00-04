#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){

    const int n = 10;
    Animal* animals[n];
    for (int i = 0; i < n; i++){
        if (i < n/2){
            animals[i] = new Dog();
        }
        else{
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < n; i++){
        delete animals[i];
    }


    Dog base;
    base.getBrain()->setIdea(0, "I want to eat");
    std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
    {
        Dog clone;
        clone = base;
        std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
        clone.getBrain()->setIdea(0, "I want to play");
        std::cout << "base idea: " << base.getBrain()->getIdea(0) << std::endl;
        std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
        std::cout << "clone's Brain address: " << clone.getBrain() << std::endl;
        std::cout << "base's Brain address: " << base.getBrain() << std::endl;
    }
    std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
        return (0);
}