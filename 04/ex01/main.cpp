#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 6;
    Animal* animals[size];

    for(int i = 0; i < size; ++i)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << "\033[0m" << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    // deep copy test
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Sniff something");

    Dog copyDog = originalDog;
    std::cout << "\033[0m" << "Original: " << originalDog.getBrain()->getIdea(0) << "\n";
    std::cout << "\033[0m" << "Copy: " << copyDog.getBrain()->getIdea(0) << "\n";

    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;

}
