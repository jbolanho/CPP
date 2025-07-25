#include "Dog.hpp"

Dog::Dog()  
{
    type = "Dog";
    std::cout << "\033[1;35m" << "[Dog] Constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)    
{
    std::cout << "\033[1;35m" << "[Dog] Copy constructor called\n";
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "\033[1;35m" << "[Dog] Assignement operator called\n";
    if(this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "\033[1;35m" << "[Dog] Destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "\033[1;35m" << "AU AU\n";
}

