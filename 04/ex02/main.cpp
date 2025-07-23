#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; ++i) 
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\033[0m" << "\n--- Making sounds ---\n";
    for (int i = 0; i < size; ++i) 
    {
        animals[i]->makeSound();
    }

    std::cout << "\033[0m" << "\n--- Bye bye ---\n";
    for (int i = 0; i < size; ++i) 
    {
        delete animals[i]; 
    }

    return 0;
}