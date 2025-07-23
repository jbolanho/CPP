#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    type = "Dog";
    std::cout << "\033[1;35m" << "[Dog] Constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "\033[1;35m" << "[Dog] Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    std::cout << "\033[1;35m" << "[Dog] Assignement operator called\n";
    if(this != &other)
    {
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "\033[1;35m" << "[Dog] Destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "\033[1;35m" << "AU AU\n";
}

Brain* Dog::getBrain() const
{
    return brain;
}
