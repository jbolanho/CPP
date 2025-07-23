#include "Animal.hpp"

Animal::Animal()       //:type("Animal")
{    
    std::cout << "\033[1;32m" << "[Animal] Constructor called\n";
}

Animal::Animal(const Animal &other) : type(other.type)
{   
    std::cout << "\033[1;32m" << "[Animal] Copy contructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{    
    std::cout << "\033[1;32m" << "[Animal] Assigned operator called\n";
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal()
{    
   std::cout << "\033[1;32m" << "[Animal] Destructor called\n";
}

// void Animal::makeSound() const
// {
//     std::cout << "\033[1;32m" << "[Animal] Generic animal sound\n";
// }

std::string Animal::getType() const
{
    return type;
}