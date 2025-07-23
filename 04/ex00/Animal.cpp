#include "Animal.hpp"

Animal::Animal() :type("Animal")
{    
    std::cout << "[Animal] Constructor called\n";
}

Animal::Animal(const Animal &other) : type(other.type)
{   
    std::cout << "[Animal] Copy contructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{    
    std::cout <<"[Animal] Assigned operator called\n";
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

Animal::~Animal()
{    
   std::cout << "[Animal] Destructor called\n";
}

void Animal::makeSound() const
{
    std::cout << "[Animal] Generic animal sound\n";
}

std::string Animal::getType() const
{
    return type;
}