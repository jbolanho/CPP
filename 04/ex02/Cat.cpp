#include "Cat.hpp"

Cat::Cat()           //: brain(new Brain())
{
    type = "Cat";
    std::cout << "\033[1;36m" << "[Cat] Constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)       //, brain(new Brain(*other.brain))
{
    std::cout << "\033[1;36m" << "[Cat] Copy constructor called\n";
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    // Animal::operator=(other);
    std::cout << "\033[1;36m" << "[Cat] Assignement operator called\n";
    if (this != &other)
    {
        // delete brain;
        // brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    // delete brain;
    std::cout << "\033[1;36m" << "[Cat] Destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "\033[1;36m" << "MIAU\n";
}

// Brain* Cat::getBrain() const
// {
//     return brain;
// }