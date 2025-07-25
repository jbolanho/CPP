#include "Cat.hpp"

Cat::Cat() 
{
    type = "Cat";
    std::cout << "\033[1;36m" << "[Cat] Constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)  
{
    std::cout << "\033[1;36m" << "[Cat] Copy constructor called\n";
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "\033[1;36m" << "[Cat] Assignement operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "\033[1;36m" << "[Cat] Destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "\033[1;36m" << "MIAU\n";
}
