#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "[Dog] Constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    std::cout << "[Dog] Assignement operator called\n";
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "AU AU\n";
}

