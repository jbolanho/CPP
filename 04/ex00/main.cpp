#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    const Animal* a = new Animal();
    const Animal* b = new Dog();
    const Animal* c = new Cat();

    std::cout << b->getType() << std::endl;
    std::cout << c->getType() << std::endl;
      
    a->makeSound(); 
    b->makeSound(); 
    c->makeSound(); 

    delete a;
    delete b;
    delete c;

    std::cout << "\n=== Wrong Polymorphism ===" << std::endl;

    const WrongAnimal* wrongA = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    wrongA->makeSound();

    delete wrongA;
    delete wrongCat;

    return 0;
}