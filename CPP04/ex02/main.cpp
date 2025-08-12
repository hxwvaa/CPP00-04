#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
    // // const Animal* meta = new Animal(); //Should not work, Animal is abstract
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // const WrongAnimal* wmeta = new WrongAnimal();
    // const WrongAnimal* wcat = new WrongCat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // std::cout << wcat->getType() << " " << std::endl;

    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // wcat->makeSound();
    // // meta->makeSound();
    // wmeta->makeSound();
    
    // delete i;
    // delete j;
    // // delete meta;
    // delete wcat;
    // delete wmeta;

    
    // const int n = 10;
    // Animal* animals[n];
    // for (int i = 0; i < n; i++){
    //     if (i < n/2){
    //         animals[i] = new Dog();
    //     }
    //     else{
    //         animals[i] = new Cat();
    //     }
    // }

    // for (int i = 0; i < n; i++){
    //     delete animals[i];
    // }

    

    // Dog base;
    // base.getBrain()->setIdea(0, "I want to eat");
    // std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
    // {
    //     // Dog clone = base;
    //     Dog clone;
    //     clone = base;
    //     std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
    //     clone.getBrain()->setIdea(0, "I want to play");
    //     std::cout << "base idea: " << base.getBrain()->getIdea(0) << std::endl;
    //     std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
    //     std::cout << "clone's Brain address: " << clone.getBrain() << std::endl;
    //     std::cout << "base's Brain address: " << base.getBrain() << std::endl;
    // }
    // std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
    // return (0);


    // ❌ These should NOT compile if Animal is abstract:
    // Animal a;
    // Animal *ptr = new Animal();

    // ✅ Derived objects
    Dog dog;
    Cat cat;

    std::cout << dog.getType() << " says: ";
    dog.makeSound();

    std::cout << cat.getType() << " says: ";
    cat.makeSound();

    std::cout << "----- Polymorphism test -----" << std::endl;

    // ✅ Array of base-class pointers
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    for (int i = 0; i < 2; i++) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    // Cleanup
    for (int i = 0; i < 2; i++)
        delete animals[i];

    return 0;

}